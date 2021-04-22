/*
Code is not commented but still so easy to understand reading the COUTS
*/
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
//**********************************************************************************************************

int main(){
	int time = 10000; //1800000 = 30min		3600000 = 1h		10000 = 10s
	cout << "HTTPD Will restart every 30 minutes";
	while (1){
		//interactive wait
		
		cout << endl << "Restarting in: 30 min" << endl;
		Sleep(300000);
		cout << "Restarting in: 25 min" << endl;
		Sleep(300000);
		cout << "Restarting in: 20 min" << endl;
		Sleep(300000);
		cout << "Restarting in: 15 min" << endl;
		Sleep(300000);
		cout << "Restarting in: 10 min" << endl;
		Sleep(300000);
		cout << "Restarting in: 5 min" << endl;
		Sleep(300000);
		cout << "RESTARTING SERVER!";
		
		ifstream archivo;
		string texto;
		archivo.open("C:\\xampp\\apache\\logs\\httpd.pid",ios::in);
		if(archivo.fail()){
			cout << "Could not read the PID from C:\\xampp\\apache\\logs\\httpd.pid, starting"<<endl;
		} else {
			cout << "PID Read performed. Stopping"<<endl;
			getline(archivo,texto);
			cout << texto << endl;
			string cmd = "C:\\windows\\system32\\taskkill.exe -F -PID " + texto + " >nul 2>&1";
			system(cmd.c_str());
			cout << "HTTPD Stopped successfully"<<endl;
		}
		//To avoid getting massive CMD windows opent, we end the cmds
		cout << "Closing extra terminals"<<endl;
		system("C:\\windows\\system32\\taskkill.exe /IM cmd.exe");
		cout << "HTTPD Starting"<<endl;
		system("start C:\\xampp\\apache_start.bat");
		archivo.close();
		//Sleep(time);
	}
}
