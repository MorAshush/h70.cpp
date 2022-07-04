#include <functional>
#include <sys/select.h> /*select*/
#include <unistd.h> /*close*/
#include <iostream>

#include "select_selector.hpp"


namespace net
{

SelectSelector::SelectSelector(TCPServer* a_server)
{
	m_server = a_server;
}
	
void SelectSelector::select()
{
	fd_set masterReadfds;
	fd_set tempReadfds;

	int listeningSocket = m_server->get_socket();

	FD_ZERO(&masterReadfds);
	FD_SET(listeningSocket, &masterReadfds);

	while(true)
	{
		FD_ZERO(&tempReadfds);
		tempReadfds = masterReadfds;

		int maxSockets = 1024;
		int activity = ::select(maxSockets, &tempReadfds, nullptr, nullptr, nullptr);
		if(activity < 0)
		{
			perror("select");
		}
		std::cout << "activity: " << activity << '\n';

		if(activity > 0)
		{
			if(FD_ISSET(listeningSocket, &tempReadfds))
			{
				m_server->check_new_clients(masterReadfds);
			}

			m_server->check_cur_clients(masterReadfds, tempReadfds, activity);
		}	
	}
}

}