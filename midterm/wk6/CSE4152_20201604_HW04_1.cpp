#include "EnvGame.h"

vector<int> solve(EnvGame &a){
    int n = a.getNodeN();
    vector<int> ans;
    ans.resize(n);
    int q = n / 3;
    int r = n % 3;
    int vict_A[n], vict_B[n];
    for(int i = 0; i < n; i++){
        vict_A[i] = -1;
        vict_B[i] = -1;
    }//initialize unfound array
//A 0 3 2
//B 0 3 2

    for(int t = 0; t < q; t++) {
        int found = 0;
        for(int i = 0; i < n && found == 0; i++)  {
            if(vict_A[i] == -1) {
                for(int j = i + 1; j < n && found == 0; j++)  {
                    if(vict_A[j] == -1) {
                        vict_A[i] += 1, vict_A[j] += 1;// 0 0 
                        a.connectWire(i, j);//choice unfound terminals on building A
                        //no need to check connectivity
                        found = 1;
                    }
                }
            }
        }

        a.goToOtherSide();
        a.cleanAllWires();
        found = 0;
        for (int i = 0; i < n && found == 0; i++) {
            for (int j = i + 1; j < n && found == 0; j++) {
                a.connectWire(i, j);//try
                if (a.checkConnectivity(i, j)) {//success
                    vict_B[i] += 1, vict_B[j] += 1;//0 0
                    for(int k = 0; k < n && found == 0; k++) {
                        if(vict_B[k] == -1) {
                            a.cleanAllWires();
                            a.connectWire(i, k);
                            vict_B[i] += 3, vict_B[k] += 3;//0 3 2
                            found = 1;
                        }
                    }
                }
                if(found == 0)    a.cleanAllWires();//failed
            }
        }
        found = 0;
        a.goToOtherSide();
        a.cleanAllWires();
        for (int i = 0; i < n && found == 0; i++) {
            for (int j = i + 1; j < n && found == 0; j++) {
                a.connectWire(i, j);
                if (a.checkConnectivity(i, j)) {
                    vict_A[i] += 3, vict_A[j] += 3;//0 3 2
                    found = 1;
                }
                a.cleanAllWires();
            }
        }
        int x, y;
        for(x = 0; x < n; x++) { 
            if(vict_A[x] == 0)  break;
        }
        for(y = 0; y < n; y++) {
            if(vict_B[y] == 0)  break;
        }
        ans[x] = y;
        vict_A[x] += 99;
        vict_B[y] += 99;

        for(x = 0; x < n; x++) { 
            if(vict_A[x] == 2)  break;
        }
        for(y = 0; y < n; y++) {
            if(vict_B[y] == 2)  break;
        }
        ans[x] = y;
        vict_A[x] += 99;
        vict_B[y] += 99;
        for(x = 0; x < n; x++) { 
            if(vict_A[x] == 3)  break;
        }
        for(y = 0; y < n; y++) {
            if(vict_B[y] == 3)  break;
        }
        ans[x] = y;
        vict_A[x] += 99;
        vict_B[y] += 99;
        a.cleanAllWires();
    }

    if (r == 1) {//3n+1
        int x, y;
        for(x = 0; x < n; x++) { 
            if(vict_A[x] == -1)  break;
        }
        for(y = 0; y < n; y++) {
            if(vict_B[y] == -1)  break;
        }
        ans[x] = y;
        vict_A[x] += 99;
        vict_B[y] += 99;
    }

    else if (r == 2) {//3n+2
        a.cleanAllWires();
        int found = 0, i;
        for(i = 0; i < n && found == 0; i++)  {
            if(vict_A[i] != -1) { //need already answered
                for(int j = i + 1; j < n && found == 0; j++)  {
                    if(vict_A[j] == -1) {
                        vict_A[i] += 1, vict_A[j] += 1;// 100(already answered) 0(not answered yet) 
                        a.connectWire(i, j);//choice unfound terminals on building A
                        //no need to check connectivity
                        found = 1;
			//printf("now: i, j = %d, %d\n", i, j);
                    }
                }
            }
        }
        a.goToOtherSide();
        a.cleanAllWires();
        found = 0;
	i-=1;
	//printf("after: i, = %d, \n", i);
        //i is already answered one
        for(int j = 0; j < n && found == 0; j++) {
            if(ans[i] != j && a.checkConnectivity(ans[i], j)) {
                for(int k = 0; k < n; k++) {
                    if(vict_A[k] == 0) {
                        ans[k] = j;
                    }
                    vict_B[j] += 1;
                }
                found = 1;
            }
            a.cleanAllWires();
        }

        int x, y;
        for(x = 0; x < n; x++) { 
            if(vict_A[x] == -1)  break;
        }
        for(y = 0; y < n; y++) {
            if(vict_B[y] == -1)  break;
        }
        ans[x] = y;
    }

    // vector<int> check;
    
    // ans.resize(n);

    // vector<vector<int>> map;

    // map.resize(n);
    // for(int j=0;j<n;j++) {map[j].clear();map[j].reserve(5);}

    // for(int i=0;i<n;i+=2){

    //     int ni = (i+1) % n ;

    //     a.cleanAllWires();
    //     a.connectWire ( i, ni);
    //     a.goToOtherSide();
 
    //     for(int j=0;j<n;j++){            
    //         for(int k=j+1;k<n;k++){
 
    //             bool light = a.checkConnectivity(j,k);
                
    //             if (light){
    //                  map[i].push_back(j);
    //                  map[i].push_back(k);
    //                  map[ni].push_back(j);
    //                  map[ni].push_back(k);
    //             }
    //         }
    //     }
    //     a.goToOtherSide();
    // }

    // for(int i=1;i<n;i+=2){
    //     int ni  = (i+1)%n ;
    //     a.cleanAllWires();

    //     a.connectWire ( i,ni );

    //     a.goToOtherSide();
 
    //     for(int j=0;j<n;j++){            
    //         for(int k=j+1;k<n;k++){
 
    //             bool light = a.checkConnectivity(j,k);
                
    //             if (light){
    //                  if( std::find (map[i].begin(), map[i].end(), j) != map[i].end() )
    //                     ans[i]=j;
    //                  if( std::find (map[i].begin(), map[i].end(), k) != map[i].end() )
    //                     ans[i]=k;
    //                  if( std::find (map[ni].begin(), map[ni].end(), j) != map[ni].end() )
    //                     ans[ni]=j;
    //                  if( std::find (map[ni].begin(), map[ni].end(), k) != map[ni].end() )
    //                     ans[ni]=k;
    //             }
    //         }
    //     }
    //     a.goToOtherSide();
    // }
    return ans;
}
