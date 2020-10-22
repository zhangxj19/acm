#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


int main(int argc, char **argv) {

		ifstream in(argv[1]);
		ifstream out(argv[2]);
		ofstream scr(argv[5]);
		ofstream log(argv[6]);

		unsigned int n;
		unsigned int correct, time;
		string byr;

		in >> n;

		if (!(out >> correct >> time >> byr)) {
			log << "BaidageJiushiNiubi" << endl;
			goto gg;
		}

		if (byr != "HaobaNanijiayouQueshiGG") {
			log << "BaidageNiubi" << endl;
			goto gg;
		}

		if (out >> byr) {
			log << "BaidageHaishiNiubi" << endl;
			goto gg;
		}

		correct ^= 0x19980129;
		time ^= 0x19980129;

		if (correct != 1) {
			scr << 0 << endl;
		} else {
			scr << n * 10 << endl;
		}
		scr << "t(ms): " << time << ".0" << endl;

		goto exit;

gg:
		scr << 0 << endl << "Invalid format" << endl;
		log << "BaidageNiubi" << endl;

exit:
		return 0;

}

