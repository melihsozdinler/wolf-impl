/*
 * Wolf Algorithm Implementation of Paper
 * Çakiroglu, Olca & Erten, Cesim & Karatas, Ömer & Sözdinler, Melih. (2009).
 * Lecture Notes in Computer Science. J. Discrete Algorithms. 7. 439-452.
 * 10.1007/978-3-540-72845-0_10.
 *
 * Copyright (C) <2021>  <Melih Sozdinler>
 * Thanks to Arda Cakiroglu, Omer Karatas, Cesim Erten
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the,
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef WOLFIMPL_H_
#define WOLFIMPL_H_

#include "BipartiteGraph.h"
#include "NodeArray.h"
#include "List.h"
#include "Array.h"
#include "Matrix.h"

typedef signed long long int integer;

template<class T>
        using list_item = typename std::list<T>::iterator;

class WolfImpl {

private:
    int wolfDebug = 0;
    int partitionCount;
    int justRunPhase1 = false;

public:
    void Run(GRAPH<int, int> &G, wolf_list<node> &A, wolf_list<node> B);

    void MatrixToGraph(GRAPH<int, int> &G, wolf_list<node> &A, wolf_list<node> &B, matrix<int> &m, bool weighted);

    matrix<int> GraphToMatrix(GRAPH<int, int> &G, wolf_list<node> A, wolf_list<node> B, bool weighted);

private:
    void merge(GRAPH<int, int> &G, wolf_list<node> &ptRow, wolf_list<node> &L, wolf_list<node> &R, node owner,
               wolf_list<node> &alt);

    void wolfPhase2(GRAPH<int, int> &G, wolf_list<node> &ptRow, node owner, wolf_list<node> alt);

    integer crossingNumber(matrix<int> &m);

    integer crossingNumber(GRAPH<int, int> &G, wolf_list<node> &A, wolf_list<node> &B);

    integer weight(GRAPH<int, int> &G, node alt1, node alt2, node ust, wolf_list<node> alt);

    int getCrossings(GRAPH<int, int> &G, wolf_list<node> &A, wolf_list<node> &B);
};

#endif
// WOLFIMPL_H_