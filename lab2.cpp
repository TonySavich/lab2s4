#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

const int N = 5;




int main()
{

    int mas[N][N];
    int v[N];

    int dop[N][N];
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            mas[i][j] = 0;
            dop[i][j] = 0;
            v[i] = 0;
        }
    }
    std::string m;
    std::string line;
    int k = 0;
    int r = 0;
    std::ifstream in("in.txt");
    if (in.is_open())
    {
        while (!in.eof()) {
            while (getline(in, line))
            {
                m = line;
                for (int i = 0; i < m.length(); i++) {
                    if (m[i] != ' ') {
                        dop[k][r] = dop[k][r] * 10 + (int)m[i] - 48;
                    }
                    else {
                        r++;
                    }
                }
                k++;
                r = 0;
            }
        }

    }
    in.close();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dop[i][j] != 0) {
                mas[i][dop[i][j]-1] = 1;

            }

        }
    }



    int dano ;
    
    std::cin >> dano;
    std::cout << std::endl;
   

    std::queue<int> ver;
    ver.push(dano - 1);

    int d[N];
    for (int i = 0; i < N; i++) {
        d[i] = 0;
    }
    std::vector <int> path[N];
    for (int j = 0; j < N; j++) {
        path[j].push_back(dano);
    }


    while (!ver.empty()) {

        int n = ver.front();
        ver.pop();
       v[n] = 2;
       for (int i = 0; i < N; i++) {
           if (mas[n][i] == 1) {
               if (v[i] ==0) {
                   v[i] = 1;
                   ver.push(i);
                   d[i] = d[n] + 1;
                   for (int j = i; j < N; j++) {
                       path[j].push_back(n+1);
                   }

               }

           }
       }

    }


 

    for (int i = 0; i < N; i++) {
        int yy = 0;
        int ppp;
        for (int j = 0; j < path[i].size(); j++) {

          if (yy != path[i][j]) {
                std::cout << path[i][j];
                ppp = path[i][j];
                if (path[i][j] != i + 1) {
                    std::cout << " -> ";
                }
            }
            yy = path[i][j];


        }
        if (ppp != i + 1) {
            std::cout << i + 1;
        }
        std::cout << std::endl;
    }

}