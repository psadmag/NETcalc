#pragma once
#include "pch.h"
#include "calc.h"//!!!!!!


unsigned int ModuleNet::calc::bin2dec(std::string k)
{
	unsigned int pow = 1, dec = 0;
	for (int i = k.size() - 1; i >= 0; i--)
	{
		if (k[i] == '1')
		{
			dec += pow;
		}
		pow = 2 * pow; //1,2,4,8,16,32...
	}
	return dec;
}
std::string ModuleNet::calc::dec2bin(unsigned int p) {
	std::string wynik = "";
	while (p) //p!=0
	{
		wynik = (p % 2 ? "1" : "0") + wynik; // zmienna=(warunek)?prawda:fałsz p%2!=0 to samo co p%2
		/*
		if (p%2){
			wynik="1"+wynik
			}else wynik="0"+wynik
		*/
		p /= 2;
	}
	int a = wynik.length();//ilu bitowa jest nasza liczba
	while (a < 8)
	{
		wynik = "0" + wynik;
		a++;
	}
	return wynik;
}
//"a.b.c.d/cidr" ->a.b.c.d
std::string ModuleNet::calc::getIpAddress(std::string ip) {
	std::stringstream s(ip);
	int a, b, c, d, e;
	char ch;
	s >> a >> ch >> b >> ch >> c >> ch >> d >> ch >> e;
	return std::to_string(a) + "." + std::to_string(b) + "." + std::to_string(c) + "." + std::to_string(d);
}
//cidr=24 -> 255.255.255.0
std::string ModuleNet::calc::cidr2DecMask(int m) {
	std::string s = "";
	std::string mask = "";
	//11111111.11111111.11000000.00000000
	int w, r;
	w = m / 8;//2
	r = m % 8;//2
	for (int i = 1; i <= w; i++) {
		mask += "255.";
	}
	for (int i = 1; i <= r; i++)
	{
		s += "1";
	}
	for (int i = r + 1; i <= 8; i++)
	{
		s += "0";
	}
	mask += std::to_string(this->bin2dec(s));
	for (int i = 1; i < 4 - w; i++) {
		mask += ".0";
	}
	return mask;
}
////"a.b.c.d/cidr" -> cidr -> decmask
std::string ModuleNet::calc::getMask(std::string ip) {
	std::stringstream s(ip);
	int a, b, c, d, e;
	char ch;
	s >> a >> ch >> b >> ch >> c >> ch >> d >> ch >> e;
	return this->cidr2DecMask(e);
}
int ModuleNet::calc::mask2cidr(std::string m)
{
	std::stringstream s(m);
	int a, b, c, d;
	std::string sbin = "", k = "1";
	char ch;
	int j = 0;
	s >> a >> ch >> b >> ch >> c >> ch >> d;
	sbin = this->dec2bin(a) + this->dec2bin(b) + this->dec2bin(c) + this->dec2bin(d);//11111111111110000000000000000000
	for (int i = 0; i < sbin.size(); i++) {
		if (sbin[i] != '0') {
			j++;
		}
		else break;
	}
	return j;
}
//192.168.25.2 -> ‭3232241922‬
//11000000.10101000.00011001.00000010
//11000000101010000001100100000010
//‭3232241922‬
unsigned int ModuleNet::calc::addressip2int(std::string address)
{
	std::stringstream s(address);
	char ch;
	int a, b, c, d;
	s >> a >> ch >> b >> ch >> c >> ch >> d;
	return this->bin2dec(this->dec2bin(a) + this->dec2bin(b) + this->dec2bin(c) + this->dec2bin(d));
}
std::string ModuleNet::calc::int2subnet(unsigned int address) {//‭3953115841‬
	std::string a, b, c, d;
	std::string bin = this->dec2bin(address);
	int ile = bin.size();
	//111010111001111111000010 11000001
	d.insert(0, bin, ile - 8, ile);//wstawiamy do d od pozycji 0 z ciagu bin od 24 znaku do 32
	bin.erase(ile - 8, 8);//kasujemy 8 ostatnich bitów
	ile = bin.length();
	c.insert(0, bin, ile - 8, ile);
	bin.erase(ile - 8, 8);//kasujemy 8 ostatnich bitów
	ile = bin.length();
	b.insert(0, bin, ile - 8, ile);
	bin.erase(ile - 8, 8);//kasujemy 8 ostatnich bitów
	ile = bin.length();
	a.insert(0, bin, 0, ile);
	return std::to_string(this->bin2dec(a)) + "." + std::to_string(this->bin2dec(b)) + "." + std::to_string(this->bin2dec(c)) + "." + std::to_string(this->bin2dec(d));
}
unsigned int ModuleNet::calc::GetBroadcast(std::string address, std::string mask)
{
	/*
	...0000000000100000000
	...0001111111111111111
	--------------------
	...0001111111111111111
	*/
	unsigned int z, a = this->addressip2int(address) & this->addressip2int(mask);
	int b = 32 - this->mask2cidr(mask); //ilosc bitow przeznaczona na hosta
	int i = 1;
	z = 1; //reprezentuje liczbe zlozona z tylu 1 (bin) ile jest w czesci hosta
	while (i < b) {
		z = (z << 1) + 1;//
		i++;
	}
	return a | z;
}
unsigned int ModuleNet::calc::Subnet(std::string address, std::string mask) {
	//...101011011
	//...111100000
	//-------------
	//...101000000
	return this->addressip2int(address) & this->addressip2int(mask);
}

void ModuleNet::calc::firstLastAddress(std::string net, std::string broadcast) {
	unsigned int x = this->addressip2int(net) + 1;
	unsigned int y = this->addressip2int(broadcast) - 1;
	this->first = this->int2subnet(x);
	this->last = this->int2subnet(y);
}

std::string ModuleNet::calc::getipv4() {
	return this->ipv4;
}
std::string ModuleNet::calc::getmask() {
	return this->mask;
}
std::string ModuleNet::calc::getsubnet() {
	return this->subnet;
}
std::string ModuleNet::calc::getbroadcast() {
	return this->broadcast;
}
unsigned int ModuleNet::calc::getipv4dec() {
	return this->ipv4dec;
}
std::string ModuleNet::calc::getFirstAddress() {
	return this->first;
}
std::string ModuleNet::calc::getLastAddress() {
	return this->last;
}

