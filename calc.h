#pragma once
#include <string>
#include <sstream>
#include <cstdlib>
namespace ModuleNet {
	class calc {
		std::string address;//dane wejsciowe
		std::string ipv4;
		std::string cidr;
		std::string mask;//notacja dziesietna kropkowa
		std::string subnet;
		std::string broadcast;
		std::string first;
		std::string last;
		unsigned int ipv4dec;
	private:
		unsigned int bin2dec(std::string k);

		std::string dec2bin(unsigned int p);
		//"a.b.c.d/cidr" ->a.b.c.d
		std::string getIpAddress(std::string ip);
		//cidr=24 -> 255.255.255.0
		std::string cidr2DecMask(int m);
		////"a.b.c.d/cidr" -> cidr -> decmask
		std::string getMask(std::string ip);
		int mask2cidr(std::string m);

		//192.168.25.2 -> ‭3232241922‬
		//11000000.10101000.00011001.00000010
		//11000000101010000001100100000010
		//‭3232241922‬
		unsigned int addressip2int(std::string address);

		std::string int2subnet(unsigned int address);
		unsigned int GetBroadcast(std::string address, std::string mask);

		unsigned int Subnet(std::string address, std::string mask);

		void firstLastAddress(std::string net, std::string broadcast);

	public:
		calc(std::string addr) {//konstruktor
			this->address = addr;
			this->ipv4 = this->getIpAddress(this->address);
			this->mask = this->getMask(this->address);
			this->cidr = this->mask2cidr(this->mask);
			this->ipv4dec = this->addressip2int(this->address);
			this->subnet = int2subnet(Subnet(getIpAddress(this->address), getMask(this->address)));
			this->broadcast = int2subnet(GetBroadcast(getIpAddress(this->address), getMask(this->address)));
			this->firstLastAddress(this->subnet, this->broadcast);
		}
		std::string getipv4();
		std::string getmask();
		std::string getsubnet();
		std::string getbroadcast();
		unsigned int getipv4dec();
		std::string getFirstAddress();
		std::string getLastAddress();
	};
};




