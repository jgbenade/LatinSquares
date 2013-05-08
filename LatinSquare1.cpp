/*
 * LatinSquare.cpp
 *
 *  Created on: 07 Feb 2013
 *      Author: gerdus
 */

#include "LatinSquare.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include <time.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;
typedef list<int> permutation;
typedef list<permutation> lsquare;

int main( );
//int printLS(list<int>& l);

struct My
{
    static bool permutationComparator    (permutation p1, permutation    p2);
};

bool My::permutationComparator    (permutation p1, permutation    p2) { return p1.front() < p2.front(); }
int branchCount_[50];
vector<vector<int> > detCount;
bool printOut ;



LatinSquare::LatinSquare() {
	// TODO Auto-generated constructor stub

}

LatinSquare::~LatinSquare() {
	// TODO Auto-generated destructor stub
}

int printUniversals(lsquare& l){
	list<list<int> >::iterator universalIt; //iterates over universals
	list<int>::iterator perm_it; //iterates over permutation

	for(universalIt=l.begin(); universalIt != l.end(); ++universalIt){

		//list<int>& universalIt = *i;
		cout<<"< ";
		for(perm_it=(*universalIt).begin(); perm_it != (*universalIt).end(); ++perm_it){

			cout<<*perm_it;
		}
		cout<<" >";
	}
	 return 0;
}


void printPerm(permutation p){
	list<int>::iterator perm_it; //iterates over permutation

	/*//print transposes to compare to alewyn
	permutation::iterator universalIt;
	int j=0;
	int arr[p.size()];
	for (universalIt = p.begin(); universalIt != p.end(); ++universalIt){
		arr[*universalIt] = j++;
	}
	permutation p1 (arr, arr + sizeof(arr) / sizeof(int) );*/

	cout<<" ";
	for(perm_it=p.begin(); perm_it != p.end(); ++perm_it){
		cout<<*perm_it;
	}
	cout<<" ";
}

void printLS(list<list<int> >& l){
	int n = l.front().size();
	int L[n][n];
	int uni_ctr = 0, row_ctr = 0;
	int i,j;
	for ( i =0; i<n; i++){
		for ( j=0; j<n; j++){
			L[i][j]=-1;
		}
	}

	list<list<int> >::iterator universalIt; //iterates over universals
	list<int>::iterator perm_it; //iterates over permutation
	uni_ctr=0;
	for(universalIt=l.begin(); universalIt != l.end(); ++universalIt){
		for(perm_it=(*universalIt).begin(); perm_it != (*universalIt).end(); ++perm_it){
			L[row_ctr][*perm_it] = uni_ctr;
			row_ctr++;
		}
		row_ctr=0;
		uni_ctr++;
	}
	uni_ctr = 0;
	//int i,j;
	for ( i =0; i<n; i++){
		for ( j=0; j<n; j++){
			if (L[i][j]>= 0)
				//cout <<  L[i][j]   <<" "<< (j==n-1? "\\\\" : "& ");
				cout <<  L[i][j]   <<" ";
			else
				cout <<    "- ";
				//cout <<    "- "<< (j==n-1? "\\\\" : "& ");
		}
		cout<< endl;
	}
	cout<< endl;

}

void printMOLSPerms( lsquare mols[], int k){
	//int k = mols;
	int m =0;
	cout << endl;
	int n = mols[0].front().size();
	stringstream outp[k][n];
	for (m=0; m<k; m++){
		//if (mols[m].size()>0){

			int L[n][n];
			int uni_ctr = 0, row_ctr = 0;
			int i,j;
			for ( i =0; i<n; i++){
				for ( j=0; j<n; j++){
					L[i][j]=-1;
				}
			}

			list<list<int> >::iterator universalIt; //iterates over universals
			list<int>::iterator perm_it; //iterates over permutation
			uni_ctr=0;
			for(universalIt=mols[m].begin(); universalIt != mols[m].end(); ++universalIt){
				for(perm_it=(*universalIt).begin(); perm_it != (*universalIt).end(); ++perm_it){
					//L[row_ctr][*perm_it] = uni_ctr;
					//row_ctr++;
					outp[m][uni_ctr] << *perm_it;
				}
				row_ctr=0;
				uni_ctr++;
			}

		//}
		//else cout<< "Empty"<< endl;
	}
	int i=0, j=0;
	for ( i =0; i<mols[k-1].size()+1; i++){
		for ( j =0; j<k; j++){
			cout<<outp[j][i].str()<<"\t";
		}
		cout<<endl;
	}
}

void printMOLS( lsquare mols[], int k){
	//int k = mols;
	int m =0;
	cout << endl;
	int n = mols[0].front().size();
	stringstream outp[k][n];
	for (m=0; m<k; m++){
		//if (mols[m].size()>0){

			int L[n][n];
			int uni_ctr = 0, row_ctr = 0;
			int i,j;
			for ( i =0; i<n; i++){
				for ( j=0; j<n; j++){
					L[i][j]=-1;
				}
			}

			list<list<int> >::iterator universalIt; //iterates over universals
			list<int>::iterator perm_it; //iterates over permutation
			uni_ctr=0;
			for(universalIt=mols[m].begin(); universalIt != mols[m].end(); ++universalIt){
				for(perm_it=(*universalIt).begin(); perm_it != (*universalIt).end(); ++perm_it){
					L[row_ctr][*perm_it] = uni_ctr;
					row_ctr++;
				}
				row_ctr=0;
				uni_ctr++;
			}
			uni_ctr = 0;
			//int i,j;
			for ( i =0; i<n; i++){
				for ( j=0; j<n; j++){
					if (L[i][j]>= 0)
						//cout <<  L[i][j]   <<" "<< (j==n-1? "\\\\" : "& ");
						outp[m][i]<<L[i][j]<<" ";
					else
						outp[m][i]<<  "- ";
					//cout <<    "- "<< (j==n-1? "\\\\" : "& ");
				}

			}
		//}
		//else cout<< "Empty"<< endl;
	}
	int i=0, j=0;
	for ( i =0; i<n; i++){
		for ( j =0; j<k; j++){
			cout<<outp[j][i].str()<<"\t";
		}
		cout<<endl;
	}
}

/*is Orthogonal accepts a relative cycle structure in the form of
 * a permutation and checks wheter the two original permutations
 * are orthonal, ie, whether the rcs has exactly one fixed point.
 * Input: perm - the permutation of the relative cycle structure to be checked
 * Output: true if orthogonal (only one fixed point)
 */
 bool isOrthogonal(permutation perm){
	list<int>::iterator perm_it; //iterates over permutation
	int row_ctr=0,fixed_ctr = 0;
	for(perm_it=perm.begin(); perm_it != perm.end(); ++perm_it){
		if (*perm_it == row_ctr) fixed_ctr++;
		row_ctr++;
	}

	if (fixed_ctr==1)
		return true;
	else
		return false;
}

permutation composition(permutation p1, permutation p2){
//TODO test whether permutations are of same length

	list<int>::iterator perm1_it; //iterates over p1
	list<int>::iterator perm2_it; //iterates over p2

	perm1_it = p1.begin();
	perm2_it = p2.begin();

	int n = p1.size();
	int p1arr[n];
	int permarr[n];

	int current = 0;
	for(perm1_it=p1.begin(); perm1_it != p1.end(); ++perm1_it){
		p1arr[current] = *perm1_it;
		current++;
	}

	permutation composite ; //= {0,0,0,0};

	for(perm2_it=p2.begin(); perm2_it != p2.end(); ++perm2_it){
		composite.push_back(p1arr[*perm2_it]);
	}

//	int ctr = 0;
//	for (perm2_it=composite.begin(); perm2_it != composite.end(); ++perm2_it){
//		cout<<*perm2_it<<" "<<ctr++<< endl;
//	}

	return composite;
}

permutation inverse(permutation p){
	int perm[p.size()];

	list<int>::iterator perm_it; //iterates over p1
	int ctr = 0;
	for (perm_it=p.begin(); perm_it != p.end(); ++perm_it){
		perm[*perm_it] = ctr++;
	}

	permutation inverse;
	int i=0;
	for (i=0; i<p.size(); i++){
		inverse.push_back(perm[i]);
	}
	//return arrToPerm(perm);
	return inverse;
}
permutation copyPerm(permutation p){
	permutation::iterator pIt;
	permutation pNew ;
	for (pIt = p.begin(); pIt!=p.end(); ++pIt){
		pNew.push_back(*pIt);
	}

	return pNew;
}

permutation rcs(permutation p1, permutation p2){
//TODO test whether permutations are of same length
	// actually just write the two permutations above each other and sort. has to be faster. although..nlogn
	return composition(p2, inverse(p1));
}
template<int k>
void permuteSymbols(lsquare partMOLS[k], lsquare newMOLS[k]){
	int i;
	for (i =0;i<k;i++){
		if (partMOLS[i].size()>0){ //if the square is still empty it cant be permuted

			lsquare::iterator permIt ;
			for (permIt = partMOLS[i].begin(); permIt != partMOLS[i].end(); ++permIt){
				newMOLS[i].push_back(*permIt);
				//TODO this was taken out in an attempt to make it slightly faster.
				//newMOLS[i].push_back(copyPerm(*permIt));
			}
			newMOLS[i].sort(My::permutationComparator);
		}
	}
	//TODO shuffle squares
}

template<int k>
void permuteMOLS(lsquare partMOLS[k], permutation rowPerm, permutation colPerm, lsquare newMOLS[k]){
//void permuteMOLS(lsquare partMOLS[], permutation rowPerm, permutation colPerm){
	//int k=2;
	//lsquare* newList = (lsquare*)malloc(k*sizeof(lsquare));
	//newList[0] =
	int i=0;
	lsquare finalMOLS[k];
	//permuteMOLS<2>()
	for (i=0; i<k; i++	){
		if (partMOLS[i].size()>0){ //if the square is not empty (otherwise it cant be permuted)

			list<list<int> >::const_iterator universalIt; //iterates over universals
			list<int>::const_iterator perm_it; //iterates over permutation

			for(universalIt=partMOLS[i].begin(); universalIt != partMOLS[i].end(); ++universalIt){
				permutation p;
				//list<int>& universalIt = *i;
				for(perm_it=(*universalIt).begin(); perm_it != (*universalIt).end(); ++perm_it){
					p.push_back(*perm_it);
				}
				//newList[i].push_back(p);
				newMOLS[i].push_back(composition(composition(colPerm, p), inverse(rowPerm)) );
			}
		}
	}

	//permuteSymbols<k>(finalMOLS, newMOLS);

//	std::list<int> third (second.begin(),second.end());  // iterating through second
}

template<int k>
void permuteMOLSRCS(lsquare partMOLS[k], permutation rowPerm, permutation colPerm, lsquare newMOLS[k]){
//void permuteMOLS(lsquare partMOLS[], permutation rowPerm, permutation colPerm){
	//int k=2;
	//lsquare* newList = (lsquare*)malloc(k*sizeof(lsquare));
	//newList[0] =
	int i=0;
	lsquare finalMOLS[k];
	//permuteMOLS<2>()
	for (i=0; i<k; i++	){
		if (partMOLS[i].size()>0){ //if the square is not empty (otherwise it cant be permuted)

			list<list<int> >::iterator universalIt; //iterates over universals
			list<int>::iterator perm_it; //iterates over permutation

			for(universalIt=partMOLS[i].begin(); universalIt != partMOLS[i].end(); ++universalIt){
				permutation p;
				//list<int>& universalIt = *i;
				for(perm_it=(*universalIt).begin(); perm_it != (*universalIt).end(); ++perm_it){
					p.push_back(*perm_it);
				}
				//newList[i].push_back(p);
				newMOLS[i].push_back(composition(composition(colPerm, p), inverse(rowPerm)) );
			}
		}
	}

	/*cout<<"Before relabelling";
		printMOLS(finalMOLS, k);
		permuteSymbols<k>(finalMOLS, newMOLS);*/

//	std::list<int> third (second.begin(),second.end());  // iterating through second
}

template<int k>
void testpermuteMOLS(lsquare partMOLS[k], permutation rowPerm, permutation colPerm, lsquare newMOLS[k], lsquare newpMOLS[k]){
//void permuteMOLS(lsquare partMOLS[], permutation rowPerm, permutation colPerm){

	int i=0; permutation p1;
	lsquare finalMOLS[k];
	for (i=0; i<k; i++	){
		if (partMOLS[i].size()>0){ //if the square is not empty (otherwise it cant be permuted)

			list<list<int> >::iterator universalIt; //iterates over universals
			list<int>::iterator perm_it; //iterates over permutation
			p1 = partMOLS[i].back(); //only goind to permute the last one

			permutation p;
		//	printPerm(p1);

			for(perm_it=(p1).begin(); perm_it != (p1).end(); ++perm_it){
				p.push_back(*perm_it);
			}

		//	printPerm(p);
			newMOLS[i].push_back(p);
			newpMOLS[i].push_back(composition(colPerm, composition(p, inverse(rowPerm))) );

		}
	}
}



/*this is a working copy of permutesymbols before starting to permute only the last symbol
 * template<int k>
void permuteMOLS(lsquare partMOLS[k], permutation rowPerm, permutation colPerm, lsquare newMOLS[k]){
//void permuteMOLS(lsquare partMOLS[], permutation rowPerm, permutation colPerm){
	//int k=2;
	//lsquare* newList = (lsquare*)malloc(k*sizeof(lsquare));
	//newList[0] =
	int i=0;
	lsquare finalMOLS[k];
	//permuteMOLS<2>()
	for (i=0; i<k; i++	){
		if (partMOLS[i].size()>0){ //if the square is still empty it cant be permuted

			list<list<int> >::iterator universalIt; //iterates over universals
			list<int>::iterator perm_it; //iterates over permutation

			for(universalIt=partMOLS[i].begin(); universalIt != partMOLS[i].end(); ++universalIt){
				permutation p;
				//list<int>& universalIt = *i;
				for(perm_it=(*universalIt).begin(); perm_it != (*universalIt).end(); ++perm_it){
					p.push_back(*perm_it);
				}
				//newList[i].push_back(p);
				finalMOLS[i].push_back(composition(colPerm, composition(p, inverse(rowPerm))) );
			}
		}
	}

	permuteSymbols<k>(finalMOLS, newMOLS);

//	std::list<int> third (second.begin(),second.end());  // iterating through second
}*/

template<int k, int n>
void printOA(int OA[k+2][n*n]){
	int i; int j; int w = n*n;
	cout << "ORTHOGONAL ARRAY"<< endl;
		for (i=0; i<k+2; i++){
			for (j=0; j<w; j++){
					cout<<	OA[i][j] << " ";
			}
			cout<< endl;
		}
}

//true if first is smaller or equal (weak ordering)
// this function has been tested and works with 1-mols and 2mols
//at the very least.  2 mols means by extension also with kmols
// 1 < 2 - TRUE
// 1 = 2 - TRUE
// 1 > 2 - FALSE
template<int k>
bool comparePartialMOLS(lsquare partMOLS1[k], lsquare partMOLS2[k]){
	lsquare::iterator permIt1[k];//arrays of iterators
	lsquare::iterator permIt2[k];
	int doneArr[k];
	int i=0;

	//doneArr keeps track of when the end of each array is reached to prevent the iterator from enumerating an array which is already on its end.
	for (i=0; i<k; i++){
		doneArr[i]=0;
	}

	int currSquare = 0;  //the number of the square currently being compared.
	for (currSquare =0; currSquare<k; currSquare++){
		//if the square is empty the iterator obv wont function properly
		//Assume for now that if one doesnt have anythiong in a square neither does the other, as they are permutations
		if (partMOLS1[currSquare].size()>0){
			permIt1[currSquare] = partMOLS1[currSquare].begin();
			permIt2[currSquare] = partMOLS2[currSquare].begin();
		}
		else {
			doneArr[currSquare] = 1;
		}

	}

	for (currSquare =0; currSquare<k; currSquare=(currSquare+1)%k){//this goes on forever, break on when iterato reaches end
		 //printPerm(*permIt1[currSquare]);
		 //printPerm(*permIt2[currSquare]);
		//cout<< lexicographical_compare((*permIt1[currSquare]).begin(), (*permIt1[currSquare]).end(), (*permIt2[currSquare]).begin(), (*permIt2[currSquare]).end() )<<endl;

		if ( lexicographical_compare((*permIt1[currSquare]).begin(), (*permIt1[currSquare]).end(), (*permIt2[currSquare]).begin(), (*permIt2[currSquare]).end() ))
			return true;
		else if ( lexicographical_compare((*permIt2[currSquare]).begin(), (*permIt2[currSquare]).end(), (*permIt1[currSquare]).begin(), (*permIt1[currSquare]).end() ))
			return false;

		//if we havent returned anything by now the elements compared are equivalent, move on to next.

		permIt1[currSquare]++;
		permIt2[currSquare]++;

		//if (permIt1[currSquare]== partMOLS1[currSquare].end() ){
		if ( (permIt1[currSquare]== partMOLS1[currSquare].end() || permIt2[currSquare]== partMOLS2[currSquare].end())
			|| doneArr[(currSquare-1+k)%k]==1){
			// so if we can move along on this square lets move along
			// remember k cycles between the squares
			doneArr[currSquare] = 1;
			int prod = 1;
			for (i=0; i<k; i++){
				prod=prod*doneArr[i];
			}
			if (prod==1)//then all permutation in all the squares have been enumerated, still equal
				return true;
		}

	}

	return true;

	//lexicographical_compare(partMOLS[0].front(), partMOLS[0].back(), ))
}

template<int k, int n>
void MOLStoOA(lsquare partMOLS[k], int OA[k+2][n*n]){
	//int n = partMOLS[0].front().size();
	int i=0;
	int j=0;
	int w = n*n;
	for (i=0; i<w; i++){
		OA[0][i] = i / n;
		OA[1][i] = (j++) %n;
	}

	int uni_ctr=0, row_ctr=0;

	/*for (i=0; i<k; i++){
			for    (j=0; j<w; j++){
				OA[i+2][j] = k-1;
			}
		}*/


	for (i=0; i<k; i++){
		uni_ctr = 0;
		lsquare::iterator universalIt; //iterates over universals
		permutation::iterator perm_it; //iterates over permutation

		for(universalIt=partMOLS[i].begin(); universalIt != partMOLS[i].end(); ++universalIt){
			row_ctr=0;
			for(perm_it=(*universalIt).begin(); perm_it != (*universalIt).end(); ++perm_it){
				OA[i+2][n*row_ctr + (*perm_it)] = uni_ctr;
				row_ctr++;
			}
			uni_ctr++;
		}
	}
	uni_ctr = 0; row_ctr = 0;
	//printOA<k,n>(OA);

return;
}

template<int k, int n>
void OAtoMOLS(int OA[k+2][n*n], lsquare newMOLS[k] ){

	map<int, int> pos_to_colidx;
	int i=0;
	int w=n*n;
	permutation parr[k][n];
	lsquare tempMOLS[k];

	for (i=0;i<k; i++){
				newMOLS[i].clear();
		}

	for (i=0; i<w; i++){
		pos_to_colidx[OA[0][i]*n + OA[1][i]] = i ;
		//map.insert(std::make_pair(OA[0][i]*n + OA[1][i], i));
	}

	int j;
	for (i=0;i<w; i++){
		for (j=0; j<k; j++){
			int col = pos_to_colidx[i];
			//cout << col<< " , "<< OA[j+2][col] << " , "<< OA[1][col]<< " " ;cout.flush();
			parr[j][ OA[j+2][col] ].push_back( OA[1][col] );
		}

	}

	for (i=0;i<k; i++){
		for (j=0; j<n; j++){
			newMOLS[i].push_back(parr[i][j]);
		}
	}

	//newMOLS=tempMOLS;
	return;
}

template<int k, int n>
void permuteOA(int OA[k+2][n*n], int p[k+2],int OANew[k+2][n*n]){
	int i=0;
	int j=0;
	int w = n*n;
	for (i=0; i<k+2; i++){
		for (j=0; j<w; j++){
			OANew[p[i]][j]	= OA[i][j];
		}
	}
	return;
}

template<int k, int n>
void getSmallest(lsquare partMOLS[k], lsquare newMOLS[k]){


	permutation colPerm;
	permutation rowPerm;

	//lsquare tempMOLS[2];
int x;
	int i=0;
	for (i=0; i<n; i++){
		rowPerm.push_back(i);
		colPerm.push_back(i);
	}

	while(next_permutation(rowPerm.begin(), rowPerm.end())){
		while(next_permutation(colPerm.begin(), colPerm.end())){
			lsquare tempMOLS[k];

			//lsquare l1; lsquare l2; tempMOLS[0] = l1; tempMOLS[1] = l2;
			//printPerm(rowPerm) ;printPerm(colPerm);

			//transposeMOLS<2>(partMOLS, transpMOLS);
			permuteMOLS<k>(partMOLS, rowPerm, colPerm, newMOLS);
			//tempmols has the postpermutation, first make this even smaller by permutin symbols


			//permuteSymbols<2>(tempMOLS, newMOLS);

			if (!comparePartialMOLS<k>(partMOLS, newMOLS) ){// if  part > final
				return;
			}
			else{
				for (x=0; x<k; x++)
					newMOLS[x].clear();
			}


		}
	}

	for (x=0; x<k; x++)
		newMOLS[x]=partMOLS[x];

	return ;
}



template<int k>
void transposeMOLS(lsquare partMOLS[k], lsquare newMOLS[k]){
	int i;
	for (i =0;i<k;i++){
		lsquare::iterator permIt ;
		permutation::iterator universalIt;
		for (permIt = partMOLS[i].begin(); permIt != partMOLS[i].end(); ++permIt){
			int j=0;
			int arr[(*permIt).size()];

			for (universalIt = (*permIt).begin(); universalIt != (*permIt).end(); ++universalIt){
				arr[*universalIt] = j++;
			}
			permutation p (arr, arr + sizeof(arr) / sizeof(int) );
			newMOLS[i].push_back(p);
		}
	}
	//TODO shuffle squares
}


template<int n>
permutation CSToPerm(int curr[n+1]){
	int i,j, currCycleLen;
	int ctr =0;
	int cycleStart;
	permutation p;

	for (i=0; i<n+1; i++){
		int j=curr[i]; //j = number of cycles of length i

		while (j-- > 0){ //while there is another cycle remaining of lenght i
			currCycleLen = i;
			cycleStart = ctr;

			while (currCycleLen>0){ //while we are still in this cycle
				p.push_back((currCycleLen==1? cycleStart: ctr+1	 ));
				currCycleLen--;
				ctr++;
			}
		}
	}

	return p;
}

template<int n>
void genCRS(int curr[n+1], int ctr, int rem, list<permutation>& csr){
	if (ctr==0){
		genCRS<n>(curr, ctr+1, rem, csr);
		return;
	}
	if (rem==0){
/*		int i=0;
		for (i=0; i<n+1; i++){
			if (curr[i]>0)
				cout<< "z_"<<i<<"^"<<curr[i]<<"  ";
		}
		cout << endl;
		printPerm(CSToPerm<n>(curr));*/

		csr.push_back(CSToPerm<n>(curr));
		return;
	}

	if (ctr<= rem){
		//first we select it and see what we get
		curr[ctr]++;
		rem = rem- ctr;
		genCRS<n>(curr, ctr, rem, csr);
		//then we dont
		curr[ctr]--;
		rem = rem+ctr;
		genCRS<n>(curr, ctr+1, rem, csr);

	}
	return;

}

template<int n>
void getCycleStructure(permutation p, int nofCycles[n+1], map<int, list<list<int> > > &cycleLength_cycles_map ){
	bool visited[n+1] ={0};
	permutation::iterator permIt;
	int permArr[n]={0};
	int i=0;



	for (permIt = p.begin(); permIt != p.end(); ++permIt){
			permArr[i++] = *permIt;
	}
	for (i=0; i<n; i++){
		if (i==permArr[i]){
			nofCycles[1]++;
			list<int> thisCycle;
			thisCycle.push_back(i);
			cycleLength_cycles_map[thisCycle.size()].push_back(thisCycle);
		}
		else
		{
			if (!visited[i]){

				list<int> thisCycle;
				int j=i;
				while (thisCycle.front() !=j){
					thisCycle.push_back(j);
					visited[j] = true;
					j = permArr[j];
				}
				nofCycles[thisCycle.size()]++;
				cycleLength_cycles_map[thisCycle.size()].push_back(thisCycle);
			}
		}
	}

	//for (i=0; i<n+1; i++)
	//	cout<< nofCycles[i]<< " ";


}

template<int n>
void genRelevantPermutations(permutation p, list<permutation>& csr){

	int i;
	int nofCycles[n+1] ={0};
	map<int, list<list<int> > > cycleLength_cycles_map;

	/*for (i=0; i<n+1; i++){
		list<list<int> > l;
		cycleLength_cycles_map[i] = l;
	}*/
	getCycleStructure<n>(p, nofCycles, cycleLength_cycles_map);

	//for some reason this doesnt work if there are more than  one cycle length 1
	//TODO fis, for now just return empty list
	if (nofCycles[1]>1)
		return;

	int nofCycleLengths = 0;
	for (i=0; i<n+1; i++)
		if (nofCycles[i] >0)
			nofCycleLengths++	;

	list<permutation> arrPossPerLength[nofCycleLengths];

/*	list<permutation> l;
	for (i=0; i<nofCycleLengths; i++){
		arrPossPerLength[i]=l;
	}*/

	int length=0;
	int ctr =0;
	for (length = 1; length<n+1; length++){
		list<permutation> arrPossibilities[nofCycles[length]];

		if (nofCycles[length]>0){

			int ind=0;
			//list<permutation> arrPossibilities[nofCycles[length]];

			list<list<int> >::iterator cycleIt;
			permutation::iterator permIt;
			//all cycles of this length
			//cout<< "Cycles of length "<< length <<": "<<endl;
			for (cycleIt = cycleLength_cycles_map[length].begin(); cycleIt !=  cycleLength_cycles_map[length].end(); ++cycleIt){
					int a=0;
 					for (permIt = (*cycleIt).begin(); a<length; ++permIt){
						std::rotate((*cycleIt).begin(), permIt, (*cycleIt).end()) ;
						// printPerm(*cycleIt);
						arrPossibilities[ind].push_back(copyPerm(*cycleIt)			);
						if (a++>0)
							--permIt;
					}
					ind++;
			}//cout<<endl;

			/*for (ind=0; ind<nofCycles[length]; ind++){
				cout<< ind<<endl;
				for (cycleIt = arrPossibilities[ind].begin(); cycleIt != arrPossibilities[ind].end(); ++cycleIt){
					printPerm(*cycleIt);
				}
			}*/

			//list<permutation> l;
			//arrPossPerLength[ctr] = l;

			if (nofCycles[length] == 1){ //no need to worry about shuffling permutations, there is only one

				for (cycleIt = arrPossibilities[0].begin(); cycleIt != arrPossibilities[0].end(); ++cycleIt){

				//	printPerm(copyPerm(*cycleIt));
				//	cout<< "s:"<<arrPossPerLength[ctr].size();
					arrPossPerLength[ctr].push_back(copyPerm(*cycleIt));

				}
				ctr++;

			}
			else{ //now we need to both shuffle and select

				vector<int> orderOfCycle;

				for (int i=0; i<nofCycles[length]; i++)
					orderOfCycle.push_back(i);

				map<int, list<permutation> > cperm_to_possibilities_map;
				int pno = 0;

				do{
					/*cout<<"start perm"<<endl;
					for (int i=0; i<nofCycles[length]; i++)
							cout<<orderOfCycle[i]<<"-";
					cout<<"end perm"<<endl;*/

					list<permutation> templ;
					list<permutation> templ2;

					for (ind=0; ind<nofCycles[length]; ind++){
						//blist<permutation> templ;
						if (ind==0){
							for (cycleIt = arrPossibilities[orderOfCycle[ind]].begin(); cycleIt != arrPossibilities[orderOfCycle[ind]].end(); ++cycleIt){
								permutation a = copyPerm(*cycleIt);
								templ.push_back(a);
								//printPerm(a);
							}
						}
						else{
							//cout<<endl<< "W"<< cperm_to_possibilities_map[pno-1].size();

							list<list<int> >::iterator partialpermIt;
							//while nextpermutation
 							for (partialpermIt = templ.begin(); partialpermIt != templ.end(); ++partialpermIt){

								for (cycleIt = arrPossibilities[orderOfCycle[ind]].begin(); cycleIt != arrPossibilities[orderOfCycle[ind]].end(); ++cycleIt){
									permutation a = copyPerm(*partialpermIt);
								 	a.insert(a.end(), (*cycleIt).begin(), (*cycleIt).end());
									templ2.push_back(a);
 								}


							}

							templ.clear();
							templ.assign(templ2.begin(), templ2.end());
							templ2.clear();


						}//end else

					}
					cperm_to_possibilities_map[pno++].assign(templ.begin(), templ.end());
				}
				while (next_permutation(orderOfCycle.begin(), orderOfCycle.end()	));

				//merge all the different list , one for each permutation, into one list
				int y;
				for (y=0; y<pno; y++	)
					arrPossPerLength[ctr].insert(arrPossPerLength[ctr].end(),cperm_to_possibilities_map[y].begin(), cperm_to_possibilities_map[y].end());

				ctr++;

			}

			//now create options for this length and every other length
			// options[length]
			//then pick one of the options per lenght

		} //end if there are cycles of this length


	} //end for every length

	/*now we assume we have all the combinations of every length in an array, for example
	 * <0> 	| <1234> 	| <567>
	 * 		| <1243>	| <675>
	 * 		| <2134>	| <756>
	 * 		| <2143>
	 * 		| <3412>
	 * 		| <4312>
	 * 		| <3421>
	 * 		| <4321>
	 *
	 * 	Select one from each column of arrposperlength
	 */

/*	int ind = 0;
	while (ind<nofCycleLengths){
		cout<<ind<<endl;
		list<list<int> >::iterator cycleIt;

		for (cycleIt = arrPossPerLength[ind].begin(); cycleIt != arrPossPerLength[ind].end(); ++cycleIt){

			printPerm(*cycleIt);
		}

		ind++;
	}*/

	////endprint
	//cout<<"==========";
	list<permutation> result;
	list<permutation> tempres;
	permutation b;
	result.push_back(b);

	list<list<int> >::iterator partialpermIt;
	list<list<int> >::iterator cycleIt;
	list<permutation> temp;
	int ind = 0;
	while (ind<nofCycleLengths){
		temp.clear();
		for (partialpermIt = result.begin(); partialpermIt != result.end(); ++partialpermIt){

			for (cycleIt = arrPossPerLength[ind].begin(); cycleIt != arrPossPerLength[ind].end(); ++cycleIt){
				permutation a = copyPerm(*partialpermIt);
				a.insert(a.end(), (*cycleIt).begin(), (*cycleIt).end());
				temp.push_back(a);
				//printPerm(a);
			}
		}
		ind++;
		result = temp;
	}
	csr = result;



}




bool isIdentity(permutation p){
	int n = p.size();
	permutation::iterator permIt ;

	int checkValue = 0;
	for (permIt = p.begin(); permIt != p.end(); ++permIt){
		if (checkValue++ != *permIt)
			return false;
	}
	cout<< "ID TRUE";
	return true;

}

bool isSmallestPermSymbols(lsquare ls, int nofPerms){
	//return true;
	lsquare::iterator permIt ;
	lsquare lsSorted;
	for (permIt = ls.begin(); permIt != ls.end(); ++permIt){
		//TODO taken out to speed up, won seconds on 58 seconds.
		//lsSorted.push_back(copyPerm(*permIt));
		lsSorted.push_back(*permIt);
	}
	lsSorted.sort(My::permutationComparator);
	/*if (lexicographical_compare(ls.begin(), ls.end(), lsSorted.begin(), lsSorted.end())){
		printUniversals(ls);
		cout<<lexicographical_compare(ls.begin(), ls.end(), lsSorted.begin(), lsSorted.end()) <<"&"<< lexicographical_compare(lsSorted.begin(), lsSorted.end(), ls.begin(), ls.end());
		printUniversals(lsSorted);cout<<"=========="<<endl;
	}else{
		printUniversals(ls);cout<<lexicographical_compare(ls.begin(), ls.end(), lsSorted.begin(), lsSorted.end()) <<"&"<< lexicographical_compare(lsSorted.begin(), lsSorted.end(), ls.begin(), ls.end());
		printUniversals(lsSorted);
		cout<<"=========="<<endl;
	}*/
	return !lexicographical_compare(ls.begin(), ls.end(), lsSorted.begin(), lsSorted.end()) && !lexicographical_compare(lsSorted.begin(), lsSorted.end(), ls.begin(), ls.end());// true if the original was smallest

}


template<int k>
bool isSmallest2(lsquare partMOLS[]){
	int n = partMOLS[0].front().size();
/*
	if (partMOLS[1].size() > n-2 && partMOLS[1].size()<n)
			return true;*/

	permutation colPerm;
	permutation rowPerm;


	int i=0;
	for (i=0; i<n; i++){
		rowPerm.push_back(i);
		colPerm.push_back(i);
	}

	if (partMOLS[1].size()<n){
	//while(next_permutation(rowPerm.begin(), rowPerm.end())){
		while(next_permutation(colPerm.begin(), colPerm.end())){

			lsquare tempMOLS[k];
			lsquare finalMOLS[k];
			testpermuteMOLS<k>(partMOLS, colPerm, colPerm, tempMOLS, finalMOLS);

			if (!comparePartialMOLS<k>(tempMOLS, finalMOLS) ){// if  part > temp
				permuteMOLS<k>(partMOLS, colPerm, colPerm, tempMOLS);
				if (!comparePartialMOLS<k>(partMOLS, tempMOLS) ){// if  part > temp
					return false;
				}
			}
		}
	//}
	}
	else
	{
		//while(next_permutation(rowPerm.begin(), rowPerm.end())){
			while(next_permutation(colPerm.begin(), colPerm.end())){
				lsquare tempMOLS[k];
				permuteMOLS<k>(partMOLS, colPerm, colPerm, tempMOLS);
				if (!comparePartialMOLS<k>(partMOLS, tempMOLS) ){// if  part > temp
					return false;
				}

			}
		//}
	}
	return true;
}

template<int k>
void changeOrder(lsquare partMOLS[k], vector<int> order , lsquare newMOLS[k]){
	int i;
	for (i=0; i<k; i++){
		newMOLS[i]= partMOLS[order[i]];
	}
}

template<int k>
void changeOrder(lsquare partMOLS[k], int first, int second , lsquare newMOLS[k]){
	newMOLS[0]=partMOLS[first];
	newMOLS[1]= partMOLS[second];
	int i=0;
	int j=2;
	for (i=0; i<k; i++){
		if (i!=first && i!=second)
			 newMOLS[j++]= partMOLS[i];
	}
}

template<int k>
void rollUp(lsquare partMOLS[k],  int pos,  permutation origP, lsquare newMOLS[k]){
	int n =partMOLS[0].front().size();
	/*int arrPerm[n];
	int i;
	permutation id;
	for (i=0;i<n;i++){
		//arrPerm[i]= (rowUp+i+n)%n;
		id.push_back(i);
	}
	//permutation p (arrPerm, arrPerm + sizeof(arrPerm) / sizeof(int) );
	printPerm(origP);
	//printMOLS(partMOLS, k);
	permuteMOLSRCS<k>(partMOLS,  origP,id,  newMOLS);
	//permuteMOLS<k>(partMOLS, id,inverse(p),  newMOLS);//TODO this is wrong
	//printMOLS(newMOLS, k);*/

	//printPerm(origP);
	list<permutation >::iterator cycleIt;
	permutation::iterator permIt;
	//permutation p1;
	int i;
	for (i=0; i<k; i++){
		for (cycleIt = partMOLS[i].begin(); cycleIt !=   partMOLS[i].end(); ++cycleIt){
			/*int a=0;
		permIt = (*cycleIt).begin();
		for (i=0;i<pos; i++)
			++permIt;*/
			permutation p;
			for (permIt = (*cycleIt).begin(); permIt!=(*cycleIt).end(); ++permIt){
				//std::rotate((*cycleIt).begin(), permIt, (*cycleIt).end()) ;
				//bprintPerm(*cycleIt);
				p.push_back((*permIt-pos+n)%n);
			}
			newMOLS[i].push_back(p);
			//ind++;
		}
	}

	//cout<<"Rotate";
	//printMOLS(newMOLS, k);

	return;
}

template<int k>
void standardForm(lsquare partMOLS[k], int rowUp, int pos ,permutation origP, lsquare newMOLS[k]){
	lsquare ruMOLS[k], sfMOLS[k];
	rollUp<k>(partMOLS, pos, origP, ruMOLS);

	int i;
	int n =partMOLS[0].front().size();
	permutation id;
	for (i=0;i<n;i++){
			//arrPerm[i]= (rowUp+i+n)%n;
			id.push_back(i);
		}
	permutation p ;
	permutation::iterator permIt;
	//for (permIt = ruMOLS[0].front().begin(); permIt!=( ruMOLS[0].front()).end(); ++permIt){
	for (permIt = origP.begin(); permIt!=(origP).end(); ++permIt){
		p.push_back((*permIt-pos+n)%n);
	}

	/*lsquare nMOLS[k];
	permuteMOLS<k>(ruMOLS, p,id,  nMOLS);
	permuteSymbols<k>(nMOLS, newMOLS	);*/

	if (!( rowUp ==0 && pos==0)){
		lsquare nMOLS[k];
		permuteMOLS<k>(ruMOLS, p,id,  nMOLS);
		permuteSymbols<k>(nMOLS, newMOLS	);
	}
	else
		permuteMOLS<k>(ruMOLS, p,id,  newMOLS);


}

vector<int> rowMeets(permutation p1, permutation p2){
	permutation::iterator permIt1;
	permutation::iterator permIt2;
	permIt2 = p2.begin();
		int i=0;
	vector<int>	res;
	res.assign(2,0);
	for (permIt1 = p1.begin(); permIt1 != p1.end(); ++permIt1) {
		if (*permIt1==*permIt2){
			res[0] = i; //row
			res[1] = *permIt1;
			return res;
		}
		permIt2++;
		i++;
	}
	return res;
}

/*
 * accept  a permutation p, of which the cycle structure is to be found and comparded to
 * another cycle structure in the form of an integer arrayu where
 * the number stored at index i is the number of cycles of length i
 * Returns 0 if the same number of cycles of every length
 *
 * Returns <0 if p < target
 * Returns >0 if p> target
 */
template<int n>
int compareCS(permutation p , int targetCS[n+1]){
	//int n = p.size();

	int thisCS[n+1] ={0};
	map<int, list<list<int> > > dummy_cycles_map;
	getCycleStructure<n>(p, thisCS ,dummy_cycles_map );

	int i;
	/*cout<<endl;printPerm(p);
	for(j=0; j<n;j++){
		cout<<thisCS[j]<<" ";}
	cout<<endl;
	for(j=0; j<n;j++){
			cout<<targetCS[j]<<" ";}
	cout<<endl;*/

	for (i=0; i<n; i++){
		//cout<<targetCS[i]<<"<>" <<thisCS[i];
		if (! (targetCS[i] == thisCS[i])	)
			return targetCS[i]-thisCS[i];
	}

	return 0; //the same

}

template<int k, int n>
bool getSmallRelCS(lsquare partMOLS[], list<permutation> &listP, list<vector<int> > &listS){
	permutation targetRCS = copyPerm(partMOLS[1].front());
	int i,j;
	//int n = partMOLS[0].front().size();

	int targetCS[n+1] ={0};
	map<int, list<list<int> > > dummy_cycles_map;
	getCycleStructure<(int) n>(targetRCS, targetCS,dummy_cycles_map );

	//list<vector<int> > squares;

	//printMOLS(partMOLS,3);
	list<permutation>::iterator permIt1;
	list<permutation>::iterator permIt2;
	//TODO should do it both ways around, or x,y == y,x??
	for(i=0; i<k-1; i++){
		for(j=i+1; j<k; j++){


			for (permIt1 = partMOLS[i].begin(); permIt1 != partMOLS[i].end(); ++permIt1) {
				for (permIt2 = partMOLS[j].begin(); permIt2 != partMOLS[j].end(); ++permIt2) {
					permutation rcsV = rcs((*permIt1), (*permIt2));
					//if this rcs is equal to smallest store in list
					//if (!lexicographical_compare(rcsV.begin(), rcsV.end(), targetRCS.begin(), targetRCS.end())
					//		and !lexicographical_compare(targetRCS.begin(), targetRCS.end(), rcsV.begin(), rcsV.end())){
					int compVal = compareCS<n>(rcsV, targetCS);
					if (compVal<0 	)
						return false;
					if (compVal==0){
					// if (true){
						vector<int> data ;
						data.assign(4, 0);
						data[0]=i;
						data[1] =j;
						vector<int> dataPos = rowMeets(*permIt1, *permIt2);
						data[2] = dataPos[0];
						data[3] = dataPos[1];
						//if (!(data[0]==0&&data[1]==1&&data[2]==0) ){
							listP.push_back(*permIt1);
							//cout<<  data[0]<<" "<<data[1]<<" "<<data[2]<<" "<<data[3]<< " perm "; printPerm(*permIt1);cout<<", "; printPerm(*permIt2); cout<<endl;
							listS.push_back(data);
						//}
					}

					//and in reverse
					rcsV = rcs((*permIt2),(*permIt1));
					//if this rcs is equal to smallest store in list
					//if (!lexicographical_compare(rcsV.begin(), rcsV.end(), targetRCS.begin(), targetRCS.end())
					//		and !lexicographical_compare(targetRCS.begin(), targetRCS.end(), rcsV.begin(), rcsV.end())){

					compVal = compareCS<n>(rcsV, targetCS);
					if (compVal<0 	)
						return false;
					if (compVal==0){
					// if(true){
						vector<int> data1 ;
						data1.assign(4, 0);
						data1[0]=j;
						data1[1] =i;
						vector<int> dataPos = rowMeets(*permIt2,*permIt1);
						data1[2] = dataPos[0];
						data1[3] = dataPos[1];
						// if (!(data1[0]==0&&data1[1]==1&&data1[2]==0) ){
							listP.push_back(*permIt2);
							//cout<<  data1[0]<<" "<<data1[1]<<" "<<data1[2]<<" "<<data1[3]<< " perm "; printPerm(*permIt2);cout<<", "; printPerm(*permIt1); cout<<endl;

							listS.push_back(data1);
						// }
					}

				}
			}


		}
	}
	return true;
}

template<int n>
list<permutation> getShuffles(permutation pOrig, permutation pNow){

	list<permutation> listShuffles ;
	genRelevantPermutations<n>(pNow, listShuffles);
	list<permutation> listtemp;

	list<permutation>::iterator pi;

	for (pi=listShuffles.begin(); pi!=listShuffles.end(); ++pi){

		listtemp.push_back( composition(pOrig,inverse(*pi)));
		//printPerm(*pi); cout<<" | "; printPerm(inverse(*pi)) ;cout<<" | ";printPerm(composition(inverse(*pi), pOrig)) ;cout<<" | ";printPerm(composition( pOrig,inverse(*pi))) ;cout<<endl;
	}

	return listtemp;
}

template<int n>
list<permutation> getShuffles(list<permutation> listShuffles, permutation pNow){


	list<permutation> listtemp;
	list<permutation>::iterator pi;

	for (pi=listShuffles.begin(); pi!=listShuffles.end(); ++pi){
		listtemp.push_back(composition(pNow,inverse(*pi)));
		//printPerm(*pi); cout<<" | "; printPerm(inverse(*pi)) ;cout<<" | ";printPerm(composition(inverse(*pi), pOrig)) ;cout<<" | ";printPerm(composition( pOrig,inverse(*pi))) ;cout<<endl;
	}

	return listtemp;
}

template<int k, int n>
bool noSmallerRCS(permutation smallestRCS, lsquare partMOLS[k], lsquare compMOLS[k] ){
	//permutation targetP =copyPerm(partMOLS[1].front());
	//permutation smallestRCS = partMOLS[1].front();
	list<permutation> listPerms; list<vector<int> > relCS;
	//so relCS has the data about where the relative cs are, and listperms the actual permutation in the square going first
	bool noneSmaller = getSmallRelCS<k, n>(partMOLS, listPerms, relCS);
	if (!noneSmaller) return false;
	list< vector<int> >::const_iterator testRel;
	list< permutation >::iterator testPermsit;
	testPermsit= listPerms.begin();
	list<permutation>::iterator permIt;int i;
	//cout<<"RELCS"<<relCS.size();
	/*for (i=0; i<k; i++){
			printPerm(partMOLS[i].back());cout<<" ";}*/
	for (testRel=relCS.begin(); testRel!=relCS.end(); testRel++){
		//cout<<endl<<" "<<(*testRel)[0]<<" "<<(*testRel)[1]<<" "<<(*testRel)[2]<<" "<<(*testRel)[3] <<endl;
		lsquare roMOLS[k], sfMOLS[k];
		/*cout<<"Before";
		printMOLS(partMOLS,k);
		printMOLSPerms(partMOLS,k);*/
		changeOrder<k>(partMOLS, (*testRel)[0],(*testRel)[1], roMOLS);
		/*cout<<"Before STD Form";
		printMOLS(roMOLS,k);
		printMOLSPerms(roMOLS,k);*/
		standardForm<k>(roMOLS, (*testRel)[2],(*testRel)[3], *testPermsit, sfMOLS);

		/*cout<<"STD Form";
		printMOLS(sfMOLS,k);
		printMOLSPerms(sfMOLS,k);*/
		permutation currPerm = sfMOLS[1].front();
		list<permutation> allShuffles = getShuffles<n>( smallestRCS, currPerm);
		// printPerm(rcs2);
		//cout << " Test shuffles";
		for (permIt = allShuffles.begin(); permIt != allShuffles.end(); ++permIt) {
			lsquare tMOLS[k], ttMOLS[k];
			//permutation realShuffle = composition(inverse( *permIt),targetP );

			//printPerm( *permIt);

			permuteMOLS<k>(sfMOLS, *permIt, *permIt, tMOLS);
			permuteSymbols<k>(tMOLS, ttMOLS);
			//printMOLSPerms(tMOLS,k); cout<<endl;
			if (!comparePartialMOLS<k>(compMOLS, ttMOLS) )// if  part > temp
			{

				/*for (i=0; i<k; i++){
					printPerm(partMOLS[i].front());cout<<" ";}*/

				//cout<< "rel CS smaller.."<< (*testRel)[0]<<" "<<(*testRel)[1]<<" "<<(*testRel)[2]<<" "<<(*testRel)[3]<< " perm "; printPerm(*permIt);cout<<endl;
				//printMOLS(tMOLS, k);
				return false;
			}
		}
		testPermsit++;
	}


	//==================\
	//TRANSPOSES??
	lsquare transpMOLS[k];
	transposeMOLS<k>(compMOLS, transpMOLS);
	list<permutation> listPerms1;
	list <vector<int> > relCS1;
	bool noneSmaller1 = getSmallRelCS<k, n>(transpMOLS, listPerms1, relCS1);
	if (!noneSmaller1) return false;
	list< vector<int> >::const_iterator testRel1;
	list< permutation >::iterator testPermsit1;
	testPermsit1= listPerms1.begin();
	//list<permutation>::iterator permIt;int i;

	for (testRel1=relCS1.begin(); testRel1!=relCS1.end(); testRel1++){
		lsquare roMOLS[k], sfMOLS[k];

		changeOrder<k>(transpMOLS, (*testRel1)[0],(*testRel1)[1], roMOLS);
		standardForm<k>(roMOLS, (*testRel1)[2],(*testRel1)[3], *testPermsit1, sfMOLS);

		permutation currPerm = sfMOLS[1].front();
		list<permutation> allShuffles = getShuffles<n>( smallestRCS, currPerm);

		for (permIt = allShuffles.begin(); permIt != allShuffles.end(); ++permIt) {
			lsquare tMOLS[k], ttMOLS[k];
			permuteMOLS<k>(sfMOLS, *permIt, *permIt, tMOLS);
			permuteSymbols<k>(tMOLS, ttMOLS);

			if (!comparePartialMOLS<k>(compMOLS, ttMOLS) )// if  part > temp
			{
				/*for (i=0; i<k; i++){
					printPerm(compMOLS[i].back());cout<<" ";}*/

				//cout<< "Initial";printMOLSPerms(compMOLS, k);
				//cout<< "New after transpose";
				//printMOLSPerms(tMOLS, k);
				//cout<< "rel CS smaller after transpose.."<< (*testRel1)[0]<<" "<<(*testRel1)[1]<<" "<<(*testRel1)[2]<<" "<<(*testRel1)[3]<< " perm "; printPerm(*permIt);cout<<endl;
								//printMOLS(tMOLS, k);
				return false;
			}
		}
		testPermsit1++;
	}

	return true;
}

template<int k, int n>
bool noSmallerRCS(permutation smallestRCS, lsquare partMOLS[k], lsquare compMOLS[k], list<permutation> listShuffles){
	//permutation targetP =copyPerm(partMOLS[1].front());
	//permutation smallestRCS = partMOLS[1].front();
	list<permutation> listPerms; list<vector<int> > relCS;
	//so relCS has the data about where the relative cs are, and listperms the actual permutation in the square going first
	bool noneSmaller = getSmallRelCS<k, n>(partMOLS, listPerms, relCS);
	if (!noneSmaller) return false;
	list< vector<int> >::const_iterator testRel;
	list< permutation >::iterator testPermsit;
	testPermsit= listPerms.begin();
	list<permutation>::iterator permIt;int i;
	//cout<<"RELCS"<<relCS.size();
	/*for (i=0; i<k; i++){
			printPerm(partMOLS[i].back());cout<<" ";}*/
	for (testRel=relCS.begin(); testRel!=relCS.end(); testRel++){
		//cout<<endl<<" "<<(*testRel)[0]<<" "<<(*testRel)[1]<<" "<<(*testRel)[2]<<" "<<(*testRel)[3] <<endl;
		lsquare roMOLS[k], sfMOLS[k];
		/*cout<<"Before";
		printMOLS(partMOLS,k);
		printMOLSPerms(partMOLS,k);*/
		changeOrder<k>(partMOLS, (*testRel)[0],(*testRel)[1], roMOLS);
		/*cout<<"Before STD Form";
		printMOLS(roMOLS,k);
		printMOLSPerms(roMOLS,k);*/
		standardForm<k>(roMOLS, (*testRel)[2],(*testRel)[3], *testPermsit, sfMOLS);

		/*cout<<"STD Form";
		printMOLS(sfMOLS,k);
		printMOLSPerms(sfMOLS,k);*/
		permutation currPerm = sfMOLS[1].front();
		list<permutation> allShuffles = getShuffles<n>( smallestRCS, currPerm);
		// printPerm(rcs2);
		//cout << " Test shuffles";
		for (permIt = allShuffles.begin(); permIt != allShuffles.end(); ++permIt) {
			lsquare tMOLS[k], ttMOLS[k];
			//permutation realShuffle = composition(inverse( *permIt),targetP );

			//printPerm( *permIt);

			permuteMOLS<k>(sfMOLS, *permIt, *permIt, tMOLS);
			permuteSymbols<k>(tMOLS, ttMOLS);
			//printMOLSPerms(tMOLS,k); cout<<endl;
			if (!comparePartialMOLS<k>(compMOLS, ttMOLS) )// if  part > temp
			{

				/*for (i=0; i<k; i++){
					printPerm(partMOLS[i].front());cout<<" ";}*/

				//cout<< "rel CS smaller.."<< (*testRel)[0]<<" "<<(*testRel)[1]<<" "<<(*testRel)[2]<<" "<<(*testRel)[3]<< " perm "; printPerm(*permIt);cout<<endl;
				//printMOLS(tMOLS, k);
				return false;
			}
		}
		testPermsit++;
	}


	//==================\
	//TRANSPOSES??
	lsquare transpMOLS[k];
	transposeMOLS<k>(compMOLS, transpMOLS);
	list<permutation> listPerms1;
	list <vector<int> > relCS1;
	bool noneSmaller1 = getSmallRelCS<k, n>(transpMOLS, listPerms1, relCS1);
		if (!noneSmaller1) return false;
	list< vector<int> >::const_iterator testRel1;
	list< permutation >::iterator testPermsit1;
	testPermsit1= listPerms1.begin();
	//list<permutation>::iterator permIt;int i;

	for (testRel1=relCS1.begin(); testRel1!=relCS1.end(); testRel1++){
		lsquare roMOLS[k], sfMOLS[k];

		changeOrder<k>(transpMOLS, (*testRel1)[0],(*testRel1)[1], roMOLS);
		standardForm<k>(roMOLS, (*testRel1)[2],(*testRel1)[3], *testPermsit1, sfMOLS);

		permutation currPerm = sfMOLS[1].front();
		list<permutation> allShuffles = getShuffles<n>( smallestRCS, currPerm);

		for (permIt = allShuffles.begin(); permIt != allShuffles.end(); ++permIt) {
			lsquare tMOLS[k], ttMOLS[k];
			permuteMOLS<k>(sfMOLS, *permIt, *permIt, tMOLS);
			permuteSymbols<k>(tMOLS, ttMOLS);

			if (!comparePartialMOLS<k>(compMOLS, ttMOLS) )// if  part > temp
			{
				/*for (i=0; i<k; i++){
					printPerm(compMOLS[i].back());cout<<" ";}*/

				//cout<< "Initial";printMOLSPerms(compMOLS, k);
				//cout<< "New after transpose";
				//printMOLSPerms(tMOLS, k);
				//cout<< "rel CS smaller after transpose.."<< (*testRel1)[0]<<" "<<(*testRel1)[1]<<" "<<(*testRel1)[2]<<" "<<(*testRel1)[3]<< " perm "; printPerm(*permIt);cout<<endl;
								//printMOLS(tMOLS, k);
				return false;
			}
		}
		testPermsit1++;
	}

	return true;
}

template<int k, int n>
bool isSmallest5(lsquare partMOLS[],lsquare origMOLS[], list<permutation> &testPerm){
	if ( testPerm.size()==0)
		return true;

	if (partMOLS[k-1].size() > 2 && partMOLS[k-1].size()<n)
				return true;
	int i;
	list<permutation>::iterator permIt;

	for (permIt = testPerm.begin(); permIt != testPerm.end(); ++permIt)
	//while (next_permutation(testPerm.front().begin(), testPerm.front().end()))
	{
		lsquare tempMOLS[k];
		//lsquare finalMOLS[k];

		permuteMOLS<k>(partMOLS, *permIt, *permIt, tempMOLS);
		//printPerm(*permIt);cout<<"-> "; printPerm(tempMOLS[k-1].front());
		if (!comparePartialMOLS<k>(origMOLS, tempMOLS) )// if  part > temp
		{
		/*
			for (i=0; i<k; i++){
				printPerm(origMOLS[i].back());cout<<"\t";}
			cout<< "smaller.. perm "; printPerm(*permIt);cout<<endl;*/
			return false;
		}
	}

	if (partMOLS[0].size()==partMOLS[k-1].size())
	{
		lsquare transpMOLS[k];
		transposeMOLS<k>(partMOLS, transpMOLS);
		lsquare transpTempMOLS[k];
		list<permutation> allPermTest = getShuffles<n>(copyPerm(origMOLS[1].front()),copyPerm(transpMOLS[1].front()));
		//genRelevantPermutations<(int)n>(transpMOLS[1].front(), allPermTest );

		for (permIt = allPermTest.begin(); permIt != allPermTest.end(); ++permIt)	{		//permuteMOLSS<k>(partMOLS, *permIt, *permIt, transpMOLS);
			permuteMOLS<k>(transpMOLS, *permIt,*permIt, transpTempMOLS);

			if (!comparePartialMOLS<k>(origMOLS, transpTempMOLS)){// if  part > transp
				/*for (i=0; i<k; i++){
					printPerm(origMOLS[i].back());cout<<"\t";}
				cout<< "transpose smaller.. perm "; printPerm(*permIt);cout<<endl;*/
				return false;
			}
		}

	}
	return true;

}

template<int k, int n>
bool isSmallest4(lsquare partMOLS[], list<permutation>& testPerm){
	//if (partMOLS[k-1].size()>2) return true;
	int i;
	/*for (i=0; i<k; i++)
		printPerm(partMOLS[i].back());*/

	if (!noSmallerRCS<k,n>(copyPerm(partMOLS[1].front()), partMOLS, partMOLS, testPerm)){
		/*for (i=0; i<k; i++)
				printPerm(partMOLS[i].back());
		cout << "smaller cs"<<endl;*/
			return false;
		}//}*/

	return true;

}

template<int k, int n> //this is fine and fastish
bool isSmallest3(lsquare partMOLS[], list<permutation> &testPerm){
	//int n = partMOLS[0].front().size();
	if ( testPerm.size()==0)
		return true;

	/*if (partMOLS[k-1].size() > 3 && partMOLS[k-1].size()<n)
			return true;*/

	list<permutation>::iterator permIt;

	for (permIt = testPerm.begin(); permIt != testPerm.end(); ++permIt) {
		lsquare tempMOLS[k];
		//lsquare finalMOLS[k];

		permuteMOLS<k>(partMOLS, *permIt, *permIt, tempMOLS);
		//printPerm(*permIt);cout<<"-> "; printPerm(tempMOLS[k-1].front());
		if (!comparePartialMOLS<k>(partMOLS, tempMOLS) )// if  part > temp
		{
			//cout<< "Test smaller"<<endl;
			return false;
		}
		/*else {
			lsquare transpMOLS[k];
			//lsquare transpTempMOLS[k];
			transposeMOLS<k>(partMOLS, transpMOLS);
			//permuteMOLS<k>(transpMOLS, *permIt, *permIt, transpTempMOLS);
			//printPerm(transpTempMOLS[k-1].front());
			//cout << "TESTING "<<
			if (!comparePartialMOLS<k>(partMOLS, transpMOLS))// if  part > transp
				return false;

		}*/

		/*testpermuteMOLS<k>(partMOLS, *permIt, *permIt, tempMOLS, finalMOLS);

			if (!comparePartialMOLS<k>(tempMOLS, finalMOLS) ){// if  part > temp
				permuteMOLS<k>(partMOLS, *permIt, *permIt, tempMOLS);

				if (!comparePartialMOLS<k>(partMOLS, tempMOLS) )// if  part > temp
					return false;

			}*/
	}
	/*cout<< "Accept"<<endl;
	}
	}
	else
	{
		//while(next_permutation(rowPerm.begin(), rowPerm.end())){
		for(permIt = testPerm.begin(); permIt != testPerm.end(); permIt++){
				lsquare tempMOLS[k];
				permuteMOLS<k>(partMOLS,  *permIt,  *permIt, tempMOLS);
				if (!comparePartialMOLS<k>(partMOLS, tempMOLS) ){// if  part > temp
					return false;
				}
			}
		//}
	}*/

	/*int i;
	vector<int> vOrder;
	for (i=0; i<k; i++)
		vOrder.push_back(i);
	permutation s,t;
	for (i=0; i<n; i++){
		s.push_back(i);t.push_back(i);
	}
	while(next_permutation(vOrder.begin(), vOrder.end())){
		lsquare toMOLS[k], trMOLS[k], ttMOLS[k];
		changeOrder<k>(partMOLS, vOrder, toMOLS);
		rollUp<k>(toMOLS,  toMOLS[0].front(), trMOLS);
		//for (permIt = testPerm.begin(); permIt != testPerm.end(); ++permIt) {
			//while (next_permutation(s.begin(), s.end())) {
	//		permuteMOLS<k>(trMOLS, *permIt, *permIt, ttMOLS);
			if (!comparePartialMOLS<k>(partMOLS, trMOLS) )// if  part > temp
			{
				return false;
			}

		//}
	}*/

	//cout<<"Sizes "<<partMOLS[0].size()<<" "<< partMOLS[k-1].size();
	//if (partMOLS[0].size()==partMOLS[k-1].size()){

	if (!noSmallerRCS<k,n>(copyPerm(partMOLS[1].front()), partMOLS, partMOLS))
		return false;

		/*permutation rcs1=copyPerm(partMOLS[1].front());
		permutation smallestRCS = partMOLS[1].front();
		list<permutation> listPerms;
		//so relCS has the data about where the relative cs are, and listperms the actual permutation in the square going first
		list <vector<int> > relCS = getSmallRelCS<k>(partMOLS, listPerms);
		list< vector<int> >::const_iterator testRel;
		list< permutation >::iterator testPermsit;
		testPermsit= listPerms.begin();
		//cout<<"RELCS"<<relCS.size();

		for (testRel=relCS.begin(); testRel!=relCS.end(); testRel++){
			cout<<" "<<(*testRel)[0]<<" "<<(*testRel)[1]<<" "<<(*testRel)[2]<<" "<<(*testRel)[3];

			lsquare roMOLS[k], sfMOLS[k];
			//permutation rcs1 = rcs;

			changeOrder<k>(partMOLS, (*testRel)[0],(*testRel)[1], roMOLS);
			//printMOLS(roMOLS, k);
			//int pos = *testRel[2];
			standardForm<k>(roMOLS, (*testRel)[2], *testPermsit, sfMOLS);

			permutation rcs2 = sfMOLS[1].front();

			list<permutation> allShuffles = getShuffles<n>(rcs1, rcs2);

			for (permIt = allShuffles.begin(); permIt != allShuffles.end(); ++permIt) {
				lsquare tMOLS[k];
				permuteMOLS<k>(sfMOLS, *permIt, *permIt, tMOLS);

				//cout<<"Before";
				//printMOLS(partMOLS,k);
				//cout<<"Result";
				//printMOLS(tMOLS,k);

				if (!comparePartialMOLS<k>(partMOLS, tMOLS) )// if  part > temp
				{
					cout<<endl<< "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" <<endl;

					return false;
				}
			}
			testPermsit++;
		}*/
	//}

	return true;
}


//the 3mols breaks somewhere in here
template<int k>
bool isSmallest(lsquare partMOLS[k]){
	permutation colPerm;
	permutation rowPerm;
	int n = partMOLS[0].front().size();

	int i=0;
	for (i=0; i<n; i++){
		rowPerm.push_back(i);
		colPerm.push_back(i);
	}


	/*if (partMOLS[k-1].size() ==0)
		return true;
	*/
	while(next_permutation(rowPerm.begin(), rowPerm.end())){
		while(next_permutation(colPerm.begin(), colPerm.end())){
			//printPerm(rowPerm);
			//printPerm(colPerm);cout<< endl;

			lsquare tempMOLS[k];
			lsquare finalMOLS[k];


			//lsquare transpFinalMOLS[k];
			//lsquare l1; lsquare l2; tempMOLS[0] = l1; tempMOLS[1] = l2;
			//printPerm(rowPerm) ;printPerm(colPerm);



			//if (partMOLS)
			//TODO this works
			permuteMOLS<k>(partMOLS, rowPerm, colPerm, tempMOLS);



				//printMOLS(tempMOLS, k);
				//printMOLS(finalMOLS, k);
			//tempmols has the postpermutation, first make this even smaller by permutin symbols

			//permuteSymbols<k>(tempMOLS, finalMOLS);

			//cout << "part";	printMOLS(partMOLS, k);
			// cout << "temp";	printMOLS(tempMOLS, k);
			// cout << "final"; printMOLS(finalMOLS, k);

						/*printMOLS(partMOLS, 2);
			printMOLS(tempMOLS,2);
			cout<<comparePartialMOLS<2>(partMOLS, tempMOLS);
			cout<< tempMOLS;
			cout<< "after permute";*/
			//if (!comparePartialMOLS(partMOLS, permuteMOLS(partMOLS, rowPerm, colPerm) ))
			//TODO this works
			if (!comparePartialMOLS<k>(partMOLS, tempMOLS) ){// if  part > temp
				return false;
			}
			// This bit is if you constantly want to check transposes tooooo
			/*else {
				lsquare transpMOLS[k];
				lsquare transpTempMOLS[k];
				transposeMOLS<k>(partMOLS, transpMOLS);
				permuteMOLS<k>(transpMOLS, rowPerm, colPerm, transpTempMOLS);
				//cout << "TESTING "<<
				if (!comparePartialMOLS<k>(partMOLS, transpTempMOLS)){// if  part > transp
						return false;
				}
			}*/
			/*else { // fi the check returned true, ie pa
				if (comparePartialMOLS<2>(finalMOLS, partMOLS)){ //now we know they are equal
					//check if they are equal because we are doing the identity perms...
					cout<< "ty";
					if (isIdentity(colPerm) && isIdentity(rowPerm)){
						//return true;
						//we should actually keep checking now, havent actually learned anything except that the identities give the same square...
					}
					else return false;
				}
				else { // so now they arent equal, part< temp
					//do nothing, hence continue checking
				}

			}*/

		}
	}
	return true;
}

template<int k, int n>
bool isSmallestConjugateMOLS(lsquare partMOLS[k]){
	return true;
 	int i;
	lsquare smallestMOLS[k] ;
	for (i=0; i<k; i++){
		smallestMOLS[i] = partMOLS[i];
	}

	list<permutation> allCSR; //list of all smalle s u0^1 cycle structures
	int cycles[n+1];
	for (i=0; i<=n+1; i++)
		cycles[i]=0;
	cycles[1] =1;
	genCRS<n>(cycles, 2, n-1, allCSR); //we may only have one overlap

	list<permutation>::iterator CSRit;

	permutation smallestRCS = partMOLS[1].front();
    lsquare t1MOLS[k], newMOLS[k];

   /* //First check for normal permutations and transpose
    if (!noSmallerRCS<k,n>(smallestRCS, partMOLS, partMOLS)){
    		for (i=0; i<k; i++)
    				printPerm(partMOLS[i].back());
    		cout << "smaller cs"<<endl;
    			return false;
    }*/

	/*lsquare l1; lsquare l2;
	tempMOLS[0] = l1; tempMOLS[1]=l2;*/

	//int n = partMOLS[0].front().size();
	int oa[k+2][n*n];
	int oanew[k+2][n*n];

	MOLStoOA<k, n>(partMOLS, oa);
	//printOA<k,n>(oa);
	//int rowls[] = {0,1,2,3,4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
	permutation p[3] ;//(rowls, rowls + n / sizeof(int) );

	for (i=0;i<k+2; i++){
			p[0].push_back(i);
			p[1].push_back(i);
			p[2].push_back(i);
	}
	p[0].remove(0);	p[0].push_back(0);p[0].remove(2);	p[0].push_front(2);
	p[1].remove(1); p[1].push_back(1);
	p[2].remove(0); p[2].remove(1); 	p[2].push_back(0); p[2].push_back(1);



	int parr[k+2];
	int perm_ctr = 0;

	//while(perm_ctr<3 ){
	do {
		i=0;

		permutation::iterator permIt;
		for (permIt = p[0].begin(); permIt !=  p[0].end(); ++permIt){
			parr[i++] =  *permIt;
		}

		permuteOA<k,n>(oa, parr, oanew);
		//cout<< "  -  oanew "; cout.flush();
		//printOA<k,n>(oanew);
		OAtoMOLS<k,n>(oanew, t1MOLS);
		//cout<< "  -  t1MOLS "; cout.flush();
		//OAtoMOLS<k,n>(oanew, (flag1? t2MOLS : t1MOLS));
		//printMOLS(t1MOLS, k);

		//getSmallest<k,n>(t1MOLS, newMOLS);
		//newmols comes bac empty
		//list<permutation> testPs =
		//if (!isSmallest5(t1MOLS, partMOLS, testPs)){
		//if( !noSmallerRCS<k,n>(smallestRCS, partMOLS, partMOLS){
		for (CSRit=allCSR.begin(); CSRit!= allCSR.end(); ++CSRit){
			//printPerm(*CSRit); cout.flush();
			if (!noSmallerRCS<k,n>(copyPerm(*CSRit), t1MOLS, partMOLS)){
				/*for (i=0; i<k; i++)
		    				printPerm(partMOLS[i].back());
		    		cout << "smaller cs"<<endl;*/
				cout <<"Not smallest conjugate";
				return false;
			}

		}
		int x;//if this wasnt smalleer, wip the mols so that a new one may be tried
		for (x=0; x<k; x++)
			t1MOLS[x].clear();

		/*if (!comparePartialMOLS<k>(partMOLS, t1MOLS)){

			cout<< "Compare"<<endl;
			printMOLS(partMOLS, k);
			cout<< "and"<<endl;
			printMOLS(newMOLS, k);
			cout <<"Not smallest conjugate";

			return false;
		}
		else
		{ //if this wasnt smalleer, wip the mols so that a new one may be tried
			int x;
			for (x=0; x<k; x++)
				newMOLS[x].clear();
		}*/
		perm_ctr++;
	}
	while (next_permutation(p[0].begin(), p[0].end()));

	return true;
}

//this seems fine for the 3mols
bool checkFit(lsquare part, permutation p){
	int n = part.front().size();
	if (n==0) return true;

	int ls[n][n];
	int x, y;
	for(x = 0; x < n; x ++) {
	    for(y = 0; y < n; y ++) ls[x][y] = -1;
	}

	int i= 0; //row
	int j =0;
	list<permutation >::iterator universalIt; //iterates over universals
	permutation::iterator perm_it; //iterates over permutation

	for(universalIt=part.begin(); universalIt != part.end(); ++universalIt){
		for(perm_it=(*universalIt).begin(); perm_it != (*universalIt).end(); ++perm_it){
			ls[i++][*perm_it] = j;
		}
		i=0;
		j++;//update universal being filled in
	}

	i=0;
	for(perm_it=p.begin(); perm_it != p.end(); ++perm_it){
		if (ls[i++][*perm_it] >=0)
			return false; //if the cell is already filled
	}
	return true;
}

bool checkOrthogonal(lsquare partMOLS[], int K, int currSquare, permutation P){
	int k = K;
	int i =0;
	for (i=0; i<k; i++){
		if (i!=currSquare){ //for every square except the current one
			lsquare::iterator perm_it;
			for(perm_it=partMOLS[i].begin(); perm_it != partMOLS[i].end(); ++perm_it){
					if(!isOrthogonal(rcs(*perm_it, P))) //check that it is orthogonal
						return false;
				}
		}
	}
	return true;
}


/*bool isCSR(permutation P){

	return true
}*/

template<int k, int n>
bool checkRCS(lsquare partMOLS[k],  int currSquare, permutation P){

	if (k<2) return true;
	/*if (partMOLS[1].size()<1) // ie if this is where we insert u_0^(0)
		return true;//return isCSR(P);*/

	int targetCS[n+1]={0};
	map<int, list<list<int> > > dummy_cycles_map;
	getCycleStructure<(int) n>(partMOLS[1].front(), targetCS,dummy_cycles_map );

	int i=0;
	for (i=0; i<k; i++){
		lsquare::iterator permIt1;
		for (permIt1=partMOLS[i].begin(); permIt1!= partMOLS[i].end(); ++permIt1){
			permutation tempPerm = rcs(*permIt1, P);
			int test =compareCS<n>(tempPerm,targetCS);
			//cout<<test<<endl;

			if (test<0 ){
				//cout << "Rel cycle structure of ";printPerm(*permIt1);cout<< " and ";printPerm(P);cout<< "is "; printPerm(tempPerm); cout <<"Smaller";
				return false;
			}
		}
	}
	return true;
}

template<int k,int n>
int findMOLS(int currSquare, lsquare partMOLS[k], int count_MOLS){

    int i=0;
	if (partMOLS[k-1].size()==n) //if the last square is filled in completely, contains n permutations
	{
		/*int s= count_MOLS%50 ;
			//if (s==0){
		if (count_MOLS<10){
				cout << endl<<count_MOLS <<endl;
				printMOLS(partMOLS, K);
			}*/
		/*bool isSmallestP = false;
		isSmallestP = isSmallestPermSymbols(partMOLS[0], 1) && isSmallestPermSymbols(partMOLS[1], 1);
		if (!isSmallestP)
			return count_MOLS;*/

		/*//taking this out to checkif we get the same resutl, so this check should be redundant. Indeed, it is
		 * for (i =2; i>0; i--){
			if (!isSmallestPermSymbols(partMOLS[i-1], 1)) //check them in reverse order
				return count_MOLS;
		}*/
		//if nothing has been returned yet then it is indeed the smallest, print MOLS and return

/*//=============================
		//check transpose

		permutation colPerm;
		permutation rowPerm;
		int n = partMOLS[0].front().size();
		int i=0;
		for (i=0; i<n; i++){
			rowPerm.push_back(i);
			colPerm.push_back(i);
		}
		//int k=3;

		while(next_permutation(rowPerm.begin(), rowPerm.end())){
			while(next_permutation(colPerm.begin(), colPerm.end())){
				lsquare transpMOLS[K];
				lsquare transpTempMOLS[K];
				lsquare transpFinalMOLS[K];

				transposeMOLS<2>(partMOLS, transpMOLS);
				permuteMOLS<2>(transpMOLS, rowPerm, colPerm, transpTempMOLS);

				permuteSymbols<2>(transpTempMOLS, transpFinalMOLS);
				//cout<< "SMALLEST" <<endl;
				//printMOLS(transpFinalMOLS,K);

				if (!comparePartialMOLS<2>(partMOLS, transpFinalMOLS) ){// if  part > final
					//cout<< "SMALLEST" <<endl;
					//printMOLS(transpFinalMOLS,K);
					//cout << "FSLSE"<<endl;
					return count_MOLS;
				}
			}
		}*/
//============================================
		//check any conjugate
	/*	permutation oaPerm;
		permutation colPerm;
		permutation rowPerm;
		int n = partMOLS[0].front().size();
		int i=0;
		for (i=0; i<n; i++){
			oaPerm.push_back(i);
			rowPerm.push_back(i);
			colPerm.push_back(i);
		}
		//int k=3;


		while(next_permutation(colPerm.begin(), colPerm.end())){
			lsquare conjMOLS[K];


			conjugateMOLS(partMOLS,oaPerm, conjMOLS);

			while(next_permutation(rowPerm.begin(), rowPerm.end())){
				while(next_permutation(colPerm.begin(), colPerm.end())){
					lsquare conjTMOLS[K];
					lsquare conjFMOLS[K];

					permuteMOLS<2>(conjMOLS, rowPerm, colPerm, conjTMOLS);
					permuteSymbols<2>(conjTMOLS, conjFMOLS);

					if (!comparePartialMOLS<2>(partMOLS, conjFMOLS) ){// if  part > final
						//cout<< "SMALLEST" <<endl;
						//printMOLS(transpFinalMOLS,K);
						//cout << "FSLSE"<<endl;
						return count_MOLS;
					}
				}
			}
		}*/
		cout<< count_MOLS<<" ";

		if (isSmallestConjugateMOLS<k, n>(partMOLS)){
			cout<<endl;
			printMOLS(partMOLS, k);
			return count_MOLS+1;
		}
		else	return count_MOLS;

//===============================================

		/*
		cout<< count_MOLS<<endl;printMOLS(partMOLS, K);

		return count_MOLS+1;*/
	}

	permutation P;

	for (i=0; i<n; i++)
		P.push_back(i);

	if(currSquare==1&& partMOLS[currSquare].size()==0	){
		list<permutation> allCSR;
		int cycles[n+1];
		for (i=0; i<=n+1; i++)
			cycles[i]=0;
		cycles[1] =1;
		genCRS<n>(cycles, 2, n-1, allCSR); //we may only have one overlap
		list<permutation>::iterator CSRit;

		for (CSRit=allCSR.begin(); CSRit!= allCSR.end(); ++CSRit){
			//No need for any of the checks, as this is only the first perm in the second square.
			//Automatically orthog, will fit (empty), forced to be RCS..
			//if (isOrthogonal(*CSRit)){
				partMOLS[currSquare].push_back(*CSRit);
				if (isSmallest<k>(partMOLS))
					count_MOLS= findMOLS<k,n>( (currSquare+1)%k, partMOLS, count_MOLS);
				partMOLS[currSquare].pop_back();
			//}
		}
	}
	else{

		while(next_permutation(P.begin(), P.end())){
			if (checkFit(partMOLS[currSquare], P)){
				if (checkRCS<k, n>(partMOLS, currSquare, P)){
					if (checkOrthogonal(partMOLS,k, currSquare, P)){
						partMOLS[currSquare].push_back(P);
						/*
						if (currSquare==k-1){
							if (isSmallest<k>(partMOLS)){
								count_MOLS= findMOLS<k,n>( (currSquare+1)%k, partMOLS, count_MOLS);
							}
						}
						else
							count_MOLS= findMOLS<k,n>( (currSquare+1)%k, partMOLS, count_MOLS);
*/
						if (isSmallest<k>(partMOLS)){
							count_MOLS= findMOLS<k,n>( (currSquare+1)%k, partMOLS, count_MOLS);
						}

						partMOLS[currSquare].pop_back();
					}
				}
			}
		}
	}

	return count_MOLS;

}

template<int k,int n>
int findMOLS2(int currSquare, lsquare partMOLS[k], int count_MOLS){
	/*if (currSquare==0)
		cout<< "*"<< partMOLS[0].size()<<"*"<<endl;*/

	int i=0;

	if (partMOLS[k-1].size()==1&& currSquare==0) //if the first row is filled in completely
	{
		printMOLS(partMOLS, k);
		return count_MOLS +1 ;
	}

	if (partMOLS[k-1].size()==n) //if the last square is filled in completely, contains n permutations
	{
		//bcout<< count_MOLS<<"&"<<endl;

		if (isSmallestConjugateMOLS<k, n>(partMOLS)){
			if (isSmallest2<k>(partMOLS)){
				printMOLS(partMOLS, k);
				return count_MOLS+1;
			}
		}
		else	return count_MOLS;

	}

	permutation P;

	list<permutation> allPermTest;

	for (i=0; i<n; i++)
		P.push_back(i);

	if(currSquare==1&& partMOLS[currSquare].size()==0	){ //o symbol on second square
		list<permutation> allCSR;
		int cycles[n+1];
		for (i=0; i<=n+1; i++)
			cycles[i]=0;
		cycles[1] =1;
		genCRS<n>(cycles, 2, n-1, allCSR); //we may only have one overlap
		list<permutation>::iterator CSRit;

		for (CSRit=allCSR.begin(); CSRit!= allCSR.end(); ++CSRit){
			//No need for any of the checks, as this is only the first perm in the second square.
			//Automatically orthog, will fit (empty), forced to be RCS..
			//if (isOrthogonal(*CSRit)){
				partMOLS[currSquare].push_back(*CSRit);
				//if (isSmallest2<k>(partMOLS))
				count_MOLS= findMOLS2<k,n>( (currSquare+1)%k, partMOLS, count_MOLS);
				partMOLS[currSquare].pop_back();
			//}
		}

		genRelevantPermutations<(int)k>(partMOLS[1].front(), allPermTest );
	}
	else{
		while(next_permutation(P.begin(), P.end())){
			if (checkFit(partMOLS[currSquare], P)){
				if (checkRCS<k, n>(partMOLS, currSquare, P)){
					if (checkOrthogonal(partMOLS,k, currSquare, P)){
						partMOLS[currSquare].push_back(P);

						//if (currSquare==k-1){
							if (isSmallest3<k>(partMOLS, allPermTest)){
								count_MOLS= findMOLS2<k,n>( (currSquare+1)%k, partMOLS, count_MOLS);
							}
						/*}
						else
							count_MOLS= findMOLS2<k,n>( (currSquare+1)%k, partMOLS, count_MOLS);
*/
						partMOLS[currSquare].pop_back();
					}
				}
			}
		}
	}

	return count_MOLS;

}

void printDots(int cursquare, int size, int k){
	int p = size*k+cursquare;
	int i=0;
	for (i=0;i<p; i++)
		cout<<".";
}
void printDots(int num){
	int i=0;
	for (i=0;i<num; i++)
		cout<<".";
}

template<int k,int n>
int findMOLS3(int currSquare, lsquare partMOLS[k], int count_MOLS, list<permutation> &testPerms){
	/*if (currSquare==0)
		cout<< "*"<< partMOLS[0].size()<<"*"<<endl;*/

	branchCount_[partMOLS[currSquare].size()*k+currSquare]++;
	int i=0;

	/*if (partMOLS[k-1].size()==1&& currSquare==0) //if the first row is filled in completely
	{
		printMOLS(partMOLS, k);
		return count_MOLS +1 ;
	}*/

	if (partMOLS[k-1].size()==n) //if the last square is filled in completely, contains n permutations
	{
		//bcout<< count_MOLS<<"&"<<endl;

		if (isSmallestConjugateMOLS<k, n>(partMOLS)){
			if (isSmallest2<k>(partMOLS)){
				printMOLS(partMOLS, k);
				return count_MOLS+1;
			}
		}
		else	return count_MOLS;

	}

	permutation P, p1;

	list<permutation> allPermTest;

	for (i=0; i<n; i++){
		P.push_back(i);
		p1.push_back(i);
	}
	p1.remove(partMOLS[currSquare].size());
	p1.push_front(partMOLS[currSquare].size());

	//if this is the first universal iln the second square we look at the class representatives
	if(currSquare==1&& partMOLS[currSquare].size()==0	){
		list<permutation> allCSR;
		int cycles[n+1];
		for (i=0; i<=n+1; i++)
			cycles[i]=0;
		cycles[1] =1;
		genCRS<n>(cycles, 2, n-1, allCSR); //we may only have one overlap
		list<permutation>::iterator CSRit;

		//cout<< allCSR.size();

		for (CSRit=allCSR.begin(); CSRit!= allCSR.end(); ++CSRit){
			//cout << "new allCSR"<<endl;
			//printMOLS(partMOLS, k);
			//No need for any of the checks, as this is only the first perm in the second square.
			//Automatically orthog, will fit (empty), forced to be RCS..
			//if (isOrthogonal(*CSRit)){
			partMOLS[currSquare].push_back(*CSRit);
			//printPerm(*CSRit);
			//if (isSmallest2<k>(partMOLS)){

				//if (isSmallest2<k>(partMOLS))
				list<permutation> allPermTest;
				//printMOLS(partMOLS, k);
				genRelevantPermutations<(int)n>(partMOLS[currSquare].front(), allPermTest );

				/*list<permutation>::iterator CSRit;
				cout<<"============="<<endl;
				for (CSRit=allPermTest.begin(); CSRit!= allPermTest.end(); ++CSRit){
					//No need for any of the checks, as this is only the first perm in the second square.
					//Automatically orthog, will fit (empty), forced to be RCS..
					printPerm(*CSRit);
				}*/

				count_MOLS= findMOLS3<k,n>( (currSquare+1)%k, partMOLS, count_MOLS, allPermTest);
				partMOLS[currSquare].pop_back();
			//}
		}

	}
	else{ //not u_0^(1)

		if (partMOLS[currSquare].size()==0 && !testPerms.size()==0){

		//	if (!testPerms.size()==0){
				//cout << " sq "<< (currSquare+1)<< ", "<< testPerms.size()<<endl;
				while(next_permutation(P.begin(), P.end())){
					if (P.front()<1){
						if (checkFit(partMOLS[currSquare], P)){

							if (checkOrthogonal(partMOLS,k, currSquare, P)){
								//printDots(currSquare, partMOLS[currSquare].size(), k); printPerm(P);
								if (checkRCS<k, n>(partMOLS, currSquare, P)){

									partMOLS[currSquare].push_back(P);

									//if (currSquare==k-1){
									if (isSmallest3<k, n>(partMOLS, testPerms)){
									//	cout<<endl;
										count_MOLS= findMOLS3<k,n>( (currSquare+1)%k, partMOLS, count_MOLS, testPerms);
									}
								//	else cout<<"...not smallest"<<endl;
									/*}
						else
							count_MOLS= findMOLS2<k,n>( (currSquare+1)%k, partMOLS, count_MOLS);
									 */
									partMOLS[currSquare].pop_back();
								}
								//else cout<<"...rcs too large"<<endl;
							}
						}
					}
				}
			}

		//}
		else{//in general
			//cout<< "Size"<< testPerms.size();
			while(next_permutation(p1.begin(), p1.end())){
				if (p1.front()==partMOLS[currSquare].size()){
					if (checkFit(partMOLS[currSquare], p1)){
						if (checkOrthogonal(partMOLS,k, currSquare, p1)){
							//	printDots(currSquare, partMOLS[currSquare].size(), k);  printPerm(p1);
							if (checkRCS<k, n>(partMOLS, currSquare, p1)){
								partMOLS[currSquare].push_back(p1);
								//if (currSquare==k-1){
								if (isSmallest3<k, n>(partMOLS, testPerms)){
								//	cout<<endl;
									count_MOLS= findMOLS3<k,n>( (currSquare+1)%k, partMOLS, count_MOLS, testPerms);
								}
							//	else cout<<"...not smallest"<<endl;
								/*}
								else
									count_MOLS= findMOLS2<k,n>( (currSquare+1)%k, partMOLS, count_MOLS);
								 */
								partMOLS[currSquare].pop_back();
							}
							//else cout<<"...rcs too large"<<endl;
						}
					}
				}
			}
		}
	}
	return count_MOLS;

}

template<int k, int n>
void buildPossibleSquare(lsquare thisSquare, int square[n][n] ){
	int r,c;
	//square = {{1}};
	for (r=0; r<n; r++){
		for (c=0;c<n;c++){
			square[r][c]=(r==0? 0 : 1);
		}
	}

	square[0][thisSquare.size()]=1;
	list<permutation>::iterator permIt;
	permutation::iterator pit;

	for (permIt=thisSquare.begin(); permIt!= thisSquare.end(); ++permIt){
		r=0;
		for (pit=(*permIt).begin(); pit != (*permIt).end(); ++pit){

			square[r++][*pit] = 0;
		}
	}

/*	int q,w;
	for (q=0;q<n;q++)	{
			for (w=0;w<n;w++){
				cout<< square[q][w]<<" ";
			}
			cout<<endl;
		}*/
}

template<int k, int n>
void generatePossiblePermsToInsertRec(int square[n][n], permutation p, int row,  list<permutation> &possiblePermList ){

	if (row==n){
		possiblePermList.push_back(copyPerm(p));
		//printPerm(p);
		return;
	}

	int i,j;
	for (i=0; i<n; i++){
		if (square[row][i] ==1){
			p.push_back(i);
			for(j=0; j<n; j++){
				if (square[j][i]==1)
					square[j][i]=-row;
			}

			generatePossiblePermsToInsertRec<k,n>(square,p, row+1,   possiblePermList	);
			p.pop_back();
			for(j=0; j<n; j++){
				if (square[j][i]==-row)
					square[j][i]=1;
			}
		}
	}
	return;
}

template<int k, int n>
void generatePossiblePermsToInsert(lsquare thisSquare,   list<permutation> &possiblePermList ){
	int square[n][n]={{1}};
	buildPossibleSquare<k,n>(thisSquare, square);
	/*int q,w;
	for (q=0;q<n;q++)	{
		for (w=0;w<n;w++){
			cout<< square[q][w]<<" ";
		}
		cout<<endl;
	}*/
	permutation p;

	generatePossiblePermsToInsertRec<k,n>(square,p, 0,   possiblePermList	) ;
	return;

}


template<int k,int n>
int findMOLS4(int currSquare, lsquare partMOLS[k], int count_MOLS, list<permutation> &testPerms){
 	int counter = partMOLS[currSquare].size()*k+currSquare-1;
	branchCount_[counter]++;
	detCount[counter].push_back(0);

 	int i=0;

    if (currSquare==0&& partMOLS[0].size()>0){
    	printDots(2*partMOLS[0].size());
    	cout<<branchCount_[partMOLS[currSquare].size()*k+currSquare-1];
    	printDots(4);

		for (i=0; i<k; i++){
			printPerm(partMOLS[i].back()	);
			cout<<" ";
		}
		cout<<endl;
	}
    if (currSquare==0&& partMOLS[0].size()==2){
    	//printMOLSPerms(partMOLS, k);
		return 0;
	}
	/*if (partMOLS[k-1].size()==1&& currSquare==0) //if the first row is filled in completely
	{
		printMOLS(partMOLS, k);
		return count_MOLS +1 ;
	}*/

	if (partMOLS[k-1].size()==n) //if the last square is filled in completely, contains n permutations
	{
		//bcout<< count_MOLS<<"&"<<endl;

		if (isSmallestConjugateMOLS<k, n>(partMOLS)){
			//if (isSmallest2<k>(partMOLS)){
				printMOLS(partMOLS, k);
				return count_MOLS+1;
			//}
		}
		else	return count_MOLS;

	}

	permutation P, p1;

	//list<permutation> allPermTest;

	for (i=0; i<n; i++){
		P.push_back(i);
		p1.push_back(i);
	}
	p1.remove(partMOLS[currSquare].size());
	p1.push_front(partMOLS[currSquare].size());

	//if this is the first universal iln the second square we look at the class representatives
	if(currSquare==1&& partMOLS[currSquare].size()==0	){
		list<permutation> allCSR;
		int cycles[n+1];
		for (i=0; i<=n+1; i++)
			cycles[i]=0;
		cycles[1] =1;
		genCRS<n>(cycles, 2, n-1, allCSR); //we may only have one overlap

		list<permutation>::iterator CSRit;

		if (printOut){
			cout << "u0^1 list has "<< allCSR.size()<< " universals - ";
			for (CSRit=allCSR.begin(); CSRit!= allCSR.end(); ++CSRit){
				printPerm(*CSRit);
			}
			cout<<endl;
		}
		int j=1;
		for (CSRit=allCSR.begin(); CSRit!= allCSR.end(); ++CSRit){

			if (printOut){
				cout << j++ << ". u0^1 = ";
				printPerm(*CSRit);
				cout<<endl;
				//cout << allCSR.size();
			}

			//No need for any of the checks, as this is only the first perm in the second square.
			//Automatically orthog, will fit (empty), forced to be RCS..


			partMOLS[currSquare].push_back(*CSRit);
			//printPerm(*CSRit);
			list<permutation> allPermTest;


			genRelevantPermutations<(int)n>(partMOLS[currSquare].front(), allPermTest );
			detCount[counter].back()++;
			count_MOLS= findMOLS4<k,n>( (currSquare+1)%k, partMOLS, count_MOLS, allPermTest);
			partMOLS[currSquare].pop_back();

		}

	}
	else{ //not u_0^(1)

		if (partMOLS[currSquare].size()==0 && !testPerms.size()==0){

		//	if (!testPerms.size()==0){
				//cout << " sq "<< (currSquare+1)<< ", "<< testPerms.size()<<endl;
				while(next_permutation(P.begin(), P.end())){
					if (P.front()<1){
						if (checkFit(partMOLS[currSquare], P)){

							if (checkOrthogonal(partMOLS,k, currSquare, P)){
								//printDots(currSquare, partMOLS[currSquare].size(), k); printPerm(P);
								if (checkRCS<k, n>(partMOLS, currSquare, P)){

									partMOLS[currSquare].push_back(P);

									//if (currSquare==k-1){
									if (isSmallest4<k, n>(partMOLS, testPerms)){
										//cout<<endl;
										detCount[counter].back()++;
										count_MOLS= findMOLS4<k,n>( (currSquare+1)%k, partMOLS, count_MOLS, testPerms);
									}
									partMOLS[currSquare].pop_back();


								}
								/*else{

									for (i=0; i<currSquare; i++){
										printPerm(partMOLS[i].back());cout<<" ";}
									printPerm(P);
									cout<< "checkrcs "; cout<<endl;
								}*/
							}
						/*	else{

								for (i=0; i<currSquare; i++){
									printPerm(partMOLS[i].back());cout<<" ";}
								printPerm(P);
								cout<< "orthog "; cout<<endl;
							}*/
						}
						/*else{

							for (i=0; i<currSquare; i++){
								printPerm(partMOLS[i].back());cout<<" ";}
							printPerm(P);
							cout<< "checkfit "; cout<<endl;
						}*/
					}
				}
			}

		//}
		else{//in general
			//cout<< "Size"<< testPerms.size();
			list<permutation> possiblePermList;
			generatePossiblePermsToInsert<k,n>(partMOLS[currSquare], possiblePermList );

			list<permutation>::iterator possPermIt;
			/*cout<< "Possible permutations to insert"<<currSquare;
			for (possPermIt=possiblePermList.begin(); possPermIt!= possiblePermList.end(); ++possPermIt){
				printPerm(*possPermIt);
			}cout<< endl;*/
			for (possPermIt=possiblePermList.begin(); possPermIt!= possiblePermList.end(); ++possPermIt){

				if (checkOrthogonal(partMOLS,k, currSquare, (*possPermIt))){
					//printDots(currSquare, partMOLS[currSquare].size(), k);  printPerm((*possPermIt));
					if (checkRCS<k, n>(partMOLS, currSquare, (*possPermIt))){
						partMOLS[currSquare].push_back((*possPermIt));

						/*if (currSquare< k-1){*/
							if (isSmallest4<k, n>(partMOLS, testPerms)){
								//cout<<endl;
								detCount[counter].back()++;
								count_MOLS= findMOLS4<k,n>( (currSquare+1)%k, partMOLS, count_MOLS, testPerms);
							}/*else{

								for (i=0; i<currSquare; i++){
									printPerm(partMOLS[i].back());cout<<"\t";}
								printPerm((*possPermIt));
								cout<< "not smallest "; cout<<endl;
							}*/


						partMOLS[currSquare].pop_back();
					}
					/*else{

												for (i=0; i<currSquare; i++){
													printPerm(partMOLS[i].back());cout<<"\t";}
												printPerm((*possPermIt));
												cout<< "checkrcs "; cout<<endl;
											}*/
				}
			/*	else{

					for (i=0; i<currSquare; i++){
						printPerm(partMOLS[i].back());cout<<"\t";}
					printPerm((*possPermIt));
					cout<< "orthog "; cout<<endl;
				}*/

			}


			/*while(next_permutation(p1.begin(), p1.end())){
				if (p1.front()==partMOLS[currSquare].size()){
					if (checkFit(partMOLS[currSquare], p1)){
						if (checkOrthogonal(partMOLS,k, currSquare, p1)){
								//printDots(currSquare, partMOLS[currSquare].size(), k);  printPerm(p1);
							if (checkRCS<k, n>(partMOLS, currSquare, p1)){
								partMOLS[currSquare].push_back(p1);
								//if (currSquare==k-1){
								if (isSmallest4<k, n>(partMOLS, testPerms)){
									//cout<<endl;
									count_MOLS= findMOLS4<k,n>( (currSquare+1)%k, partMOLS, count_MOLS, testPerms);
								}
								//else cout<<"...not smallest"<<endl;
								}
								else
									count_MOLS= findMOLS2<k,n>( (currSquare+1)%k, partMOLS, count_MOLS);

								partMOLS[currSquare].pop_back();
							}
							else{

								for (i=0; i<currSquare; i++){
									printPerm(partMOLS[i].back());cout<<"\t";}
								printPerm(p1);
								cout<< "checkrcs "; cout<<endl;
							}
						}
						else{

							for (i=0; i<currSquare; i++){
								printPerm(partMOLS[i].back());cout<<"\t";}
							printPerm(p1);
							cout<< "orthog "; cout<<endl;
						}
					}
					else{

						for (i=0; i<currSquare; i++){
							printPerm(partMOLS[i].back());cout<<"\t";}
						printPerm(p1);
						cout<< "checkfit "; cout<<endl;
					}
				}
			}*/
		}
	}
	return count_MOLS;

}

/*
 * Returns false if not smallest, true if smallest
 */
template<int k, int n>
bool testAllShufflesOrders(lsquare mols[k]){
	int i;
	permutation p1, p2;
	vector<int> vOrder;
	for (i=0; i<k; i++)
		vOrder.push_back(i);
	for (i=0; i<n; i++){
			p1.push_back(i);
			p2.push_back(i);}
	//while(next_permutation(vOrder.begin(), vOrder.end())){
		cout<<"order";
		for (i=0; i<k; i++)
				cout<<i<<" ";
		lsquare toMOLS[k], trMOLS[k], tMOLS[k];
		//changeOrder<k>(mols, vOrder, toMOLS);

		//standardForm<k>(toMOLS, 1,0, toMOLS[0].front(), trMOLS);
		//list<permutation> allPermTest;
		//genRelevantPermutations<(int)n>(trMOLS[1].front(), allPermTest );

		if (!noSmallerRCS<k,n>(copyPerm(mols[1].front()) , mols, mols)) {
			cout<< "this isnt smallest!!A";
			printMOLS(mols, k);
			return false;
		}

		lsquare tm[k];
/*
		while(next_permutation(p1.begin(), p1.end())){
			while(next_permutation(p2.begin(), p2.end())){

				permuteMOLS<k>(trMOLS, p1, p2, tm);

				if ( !comparePartialMOLS<k>(mols, tm) )// if  part > temp
				{

								for (i=0; i<k; i++){
									printPerm(origMOLS[i].back());cout<<"\t";}
								cout<< "smaller.. perm "; printPerm(*permIt);cout<<endl;
					return false;
				}
				else{
					tm[0].clear(); tm[1].clear(); tm[2].clear();
				}
			}
		}*/

		transposeMOLS<k>(trMOLS, tMOLS);
		if (!noSmallerRCS<k,n>(copyPerm(tMOLS[1].front()) , tMOLS, mols)) {
			cout<< "this isnt smallest!!B";
			return false;
		}
		while(next_permutation(p1.begin(), p1.end())){
			while(next_permutation(p2.begin(), p2.end())){

				permuteMOLS<k>(tMOLS, p1, p2, tm);

				if ( !comparePartialMOLS<k>(mols, tm) )// if  part > temp
				{

					for (i=0; i<k; i++){
						printPerm(tMOLS[i].back());cout<<"\t";}
					//cout<< "smaller.. perm "; printPerm(*permIt);cout<<endl;
					return false;
				}
				else{
					tm[0].clear(); tm[1].clear(); tm[2].clear();
				}
			}
		}

	//}

	return true;
}

template<int k, int n>
bool testAllOrders(lsquare mols[k]){
	int i;
	permutation p1, p2;
	vector<int> vOrder;
	for (i=0; i<k; i++)
		vOrder.push_back(i);
	for (i=0; i<n; i++){
			p1.push_back(i);
			p2.push_back(i);}

	cout<< "Order "<<vOrder[0]<<vOrder[1]<<vOrder[2];
	printMOLSPerms(mols, k);


	lsquare t1[k];
	transposeMOLS<k>(mols, t1);
	cout<<"Transpose";printMOLSPerms(t1, k);

	while(next_permutation(vOrder.begin(), vOrder.end())){
		/*cout<<"order";
		for (i=0; i<k; i++)
				cout<<i<<" ";*/
		lsquare toMOLS[k], trMOLS[k], tMOLS[k];

		changeOrder<k>(mols, vOrder, toMOLS);
		//standardForm<k>(toMOLS, 1,0, toMOLS[0].front(), trMOLS);
		cout<< "Order "<<vOrder[0]<<vOrder[1]<<vOrder[2];
		printMOLSPerms(toMOLS, k);
		//list<permutation> allPermTest;
		//genRelevantPermutations<(int)n>(trMOLS[1].front(), allPermTest );

		/*if (!noSmallerRCS<k,n>(copyPerm(mols[1].front()) , mols, mols)) {
			cout<< "this isnt smallest!!A";
			printMOLS(mols, k);
			return false;
		}*/

		lsquare tm[k];
/*
		while(next_permutation(p1.begin(), p1.end())){
			while(next_permutation(p2.begin(), p2.end())){

				permuteMOLS<k>(trMOLS, p1, p2, tm);

				if ( !comparePartialMOLS<k>(mols, tm) )// if  part > temp
				{

								for (i=0; i<k; i++){
									printPerm(origMOLS[i].back());cout<<"\t";}
								cout<< "smaller.. perm "; printPerm(*permIt);cout<<endl;
					return false;
				}
				else{
					tm[0].clear(); tm[1].clear(); tm[2].clear();
				}
			}
		}*/

		transposeMOLS<k>(toMOLS, tMOLS);
		cout<<"Transpose"; printMOLSPerms(tMOLS, k);
		/*if (!noSmallerRCS<k,n>(copyPerm(tMOLS[1].front()) , tMOLS, mols)) {
			cout<< "this isnt smallest!!B";
			return false;
		}
		while(next_permutation(p1.begin(), p1.end())){
			while(next_permutation(p2.begin(), p2.end())){

				permuteMOLS<k>(tMOLS, p1, p2, tm);

				if ( !comparePartialMOLS<k>(mols, tm) )// if  part > temp
				{

					for (i=0; i<k; i++){
						printPerm(tMOLS[i].back());cout<<"\t";}
					//cout<< "smaller.. perm "; printPerm(*permIt);cout<<endl;
					return false;
				}
				else{
					tm[0].clear(); tm[1].clear(); tm[2].clear();
				}
			}
		}*/

	}

	return true;
}

int main()
{
	/*std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	std::cin.rdbuf(cinbuf);   //reset to standard input again*/

	printOut=true;
	std::ofstream out("out28_1tree.txt");
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!




/*
	list<list<int> >::iterator universalIt; //iterates over universals
	for(universalIt=al.begin(); universalIt != al.end(); ++universalIt){
		cout<< isOrthogonal(*universalIt)<<endl;
	}

	composition(al.front(), al.back());
	rcs(al.front(), al.back());*/

	int n=8;
	int k=2;
	int i=0;
	permutation ss;// ={0,1,2,3,4,5,6,7,8} ;
	//permutation ssp = (permutation)ss;
	for (i=0;i<n; i++){

		ss.push_back(i);
	}

	for (i=0; i<50;i++){
		branchCount_[i]=0;
		vector<int>	 v;
		detCount.push_back(v);
	}
/*	int r1[] = {0,2,1,4,3,6,5};
	//int r2[] = {0,3,1,2,5,4};
	permutation porig (r1, r1 + sizeof(r1) / sizeof(int) );
	//permutation pnow (r2, r2 + sizeof(r2) / sizeof(int) );
	list<permutation> lll ;
	genRelevantPermutations<(int) 7>(porig, lll);
	list<permutation>::iterator permIt;

	for (permIt = lll.begin(); permIt!=lll.end(); ++permIt){
		printPerm(*permIt);

	}
	cout << endl;*/


	/*int rowls01[] = {0,1,2,3,4,5,6};
	int rowls02[] = {0,2,1,4,3,6,5};
	int rowls03[] = {0,3,4,5,6,1,2};
	int rowls11[] = {1,0,3,2,6,4,5};
	int rowls12[] = {1,6,0,5,4,2,3};
	int rowls13[] = {1,5,2,6,3,0,4};
	int rowls21[] = {2,5,4,1,0,6,3};
	int rowls22[] = {2,1,5,0,6,3,4};
	int rowls23[] = {2,6,1,3,5,4,0};
	permutation LS01 (rowls01, rowls01 + sizeof(rowls01) / sizeof(int) );
	permutation LS02 (rowls02, rowls02 + sizeof(rowls02) / sizeof(int) );
	permutation LS03 (rowls03, rowls03 + sizeof(rowls03) / sizeof(int) );
	permutation LS11 (rowls11, rowls11 + sizeof(rowls11) / sizeof(int) );
	permutation LS12 (rowls12, rowls12 + sizeof(rowls12) / sizeof(int) );
	permutation LS13 (rowls13, rowls13 + sizeof(rowls13) / sizeof(int) );
	permutation LS21 (rowls21, rowls21 + sizeof(rowls21) / sizeof(int) );
	permutation LS22 (rowls22, rowls22 + sizeof(rowls22) / sizeof(int) );
	permutation LS23 (rowls23, rowls23 + sizeof(rowls23) / sizeof(int) );
	lsquare mtmols[3], mttmols[3];      lsquare l1, l2, l3;
	l1.push_back(LS01);l1.push_back(LS11); l1.push_back(LS21);
	l2.push_back(LS02);l2.push_back(LS12); l2.push_back(LS22);
	l3.push_back(LS03);l3.push_back(LS13); l3.push_back(LS23);
	mttmols[0]=l1; mttmols[1]=l2; mttmols[2]=l3;
	mtmols[0]=l1; mtmols[1]=l3; mtmols[2]=l2;

	cout<<"W"<< noSmallerRCS<(int)3, (int)7>(copyPerm(mttmols[1].front()), mttmols, mttmols)<<endl;
	//cout << testAllOrders<(int)3, (int)6>(mttmols)<<endl;*/

	list<permutation> LS;
	/*printPerm(LS2);
	printPerm(inverse(LS2));
	printPerm(composition(LS2,inverse(LS2)));
	printPerm(rcs(LS2,LS3));*/

	LS.push_front(ss);//LS.push_back(LS2);
	/*l2.push_front(LS2);
	l3.push_front(LS3);*/

	lsquare mols[k];
	mols[0] = LS;

	/*permutation::iterator permIt;
	std::list<int>::iterator location =std::find(ss.begin(), ss.end(), 2);
	i=0;
	for (permIt = ss.begin(); i<n; ++permIt){
		std::rotate(ss.begin(), permIt, ss.end()) ;
	//printPerm(ss);
	 if (i++>0)
		 --permIt;
	}*/

	clock_t t;
	t = clock();
	cout<<   k << " MOLS of order "<< n<<endl;

	list<permutation> allCSR;
/*	int cycles[n+1];
	for (i=0; i<=n+1; i++)
			cycles[i]=0;

	genCRS<5>(cycles, 0, n, allCSR);
	cout<< allCSR.size()<<endl;
	list<permutation>::iterator CSRit;
	list<permutation>::iterator RPit;

	for (CSRit=allCSR.begin(); CSRit!= allCSR.end(); ++CSRit){
		//No need for any of the checks, as this is only the first perm in the second square.
		//Automatically orthog, will fit (empty), forced to be RCS..
		list<permutation> relPerm;
		cout<<"============="<<endl;
		printPerm(*CSRit);
		cout<< " RelevantPerms "<<endl;
		genRelevantPermutations<(int) 5>(*CSRit, relPerm);

		for (RPit=relPerm.begin(); RPit!= relPerm.end(); ++RPit){
				//No need for any of the checks, as this is only the first perm in the second square.
				//Automatically orthog, will fit (empty), forced to be RCS..
				printPerm(*RPit);


			}
	}*/


	int numM = findMOLS4<(int)2, (int)8 >(1,mols,0, allCSR) ;
	cout<< numM << " MOLS found"<<endl;

	for (i=0; i<n*k;i++)
				cout<<branchCount_[i]<<" ";
	cout<<endl;
	for (i=0; i< n; i++){
		cout<< branchCount_[k-1 +i*k] <<" takke op vlak "<<i<<endl;

	}
	vector<int>::const_iterator vit;

	for (i=0; i< k*n; i++){
		for (vit = detCount[i].begin(); vit!= detCount[i].end(); vit++)
			cout<< *vit<< ", ";
		cout<< " opsies na "<<i/k<<"."<<i%k<<endl;
	}

	t = clock() - t;
	cout<<  t/1000000.0 << " seconds"<< endl;
	std::cout.rdbuf(coutbuf); //reset to standard output again
	//cout<< numM << " MOLS found"<<endl;
	//cout<< numM<< "MOLS found";
	cout<<  t/1000000.0 << " seconds"<< endl;


	for (i=0; i<n*k;i++)
			cout<<branchCount_[i]<<" ";


	return true;

}


