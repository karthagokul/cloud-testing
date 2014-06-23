/* Copyright (C) <2014>  Gokul Kartha <kartha.gokul@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**/

#include "sysutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>

std::string SysUtils::getMACAddress(const std::string &aInterfaceName)
{
    struct ifreq ifr;
    int sock, j, k;
    char *p, addr[32], mask[32], mac[32];
    sock=socket(PF_INET, SOCK_STREAM, 0);
    if (-1==sock) {
        perror("socket() ");
        return std::string("");
    }
    strncpy(ifr.ifr_name,aInterfaceName.c_str(),sizeof(ifr.ifr_name)-1);
    ifr.ifr_name[sizeof(ifr.ifr_name)-1]='\0';


    if (-1==ioctl(sock, SIOCGIFADDR, &ifr)) {
        perror("ioctl(SIOCGIFADDR) ");
        return std::string("");
    }
    p=inet_ntoa(((struct sockaddr_in *)(&ifr.ifr_addr))->sin_addr);
    strncpy(addr,p,sizeof(addr)-1);
    addr[sizeof(addr)-1]='\0';


    if (-1==ioctl(sock, SIOCGIFNETMASK, &ifr)) {
        perror("ioctl(SIOCGIFNETMASK) ");
        return std::string("");
    }
    p=inet_ntoa(((struct sockaddr_in *)(&ifr.ifr_netmask))->sin_addr);
    strncpy(mask,p,sizeof(mask)-1);
    mask[sizeof(mask)-1]='\0';


    if (-1==ioctl(sock, SIOCGIFHWADDR, &ifr)) {
        perror("ioctl(SIOCGIFHWADDR) ");
        return std::string("");
    }
    for (j=0, k=0; j<6; j++) {
        k+=snprintf(mac+k, sizeof(mac)-k-1, j ? ":%02X" : "%02X",
                    (int)(unsigned int)(unsigned char)ifr.ifr_hwaddr.sa_data[j]);
    }
    mac[sizeof(mac)-1]='\0';


    //    printf("\n");
    //    printf("name:    %s\n",ifr.ifr_name);
    //    printf("address: %s\n",addr);
    //    printf("netmask: %s\n",mask);
    //    printf("macaddr: %s\n",mac);
    //    printf("\n");

    close(sock);
    return std::string(mac);

}
