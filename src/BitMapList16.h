#ifndef BIT_MAP_LIST_16_H
#define BIT_MAP_LIST_16_H


struct BitMapList16Entry {

	char numBits;
	char posns[16];

};

class BitMapList16 {

	BitMapList16Entry *entries;

private:

	int numBits;


public:

	BitMapList16() {
		entries = new BitMapList16Entry[65536];
	}

	~BitMapList16() {
		delete[] entries;
	}


	void initialise() {
				 
		//std::cout << "\nInitialising ...";
		for (int i=0; i<65536; i++) {

			//std::cout << "\n\n-- " << i << "\n";

			numBits = 0;
			entries[i].numBits = 0;			
			
			for (size_t b=0; b<16; b++) {
				if (i & (1 << b)) {
					entries[i].posns[numBits] = b;
					numBits++;
					//std::cout << " " << b;
				}
			}

			entries[i].numBits = numBits;
		}
	}

	void add( unsigned short idx, int* counts, int weight ) {
		//std::cout << "\n--  " << idx << " ... " << entries[idx].numBits;

		for (int i=0; i<entries[idx].numBits; i++) {
			counts[entries[idx].posns[i]] += weight;
		}
	}

	inline void add1( unsigned short idx, int* counts ) {
		//std::cout << "\n--  " << idx << " ... " << entries[idx].numBits;

		int num = entries[idx].numBits;
		int posn;
		for (int i=0; i<num; i++) {
			posn = entries[idx].posns[i];
			counts[posn]++;
		}
	}

};




#endif	/* BIT_MAP_LIST_16_H */


