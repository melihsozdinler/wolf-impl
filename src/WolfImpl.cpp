#include "WolfImpl.h"

List<node> WolfImpl::Run(GRAPH<int, int> &G, List<node> &A, List<node> &B) {
    int i, j, k, neighbourWeight;
    int leftsum = 0, rightsum = 0;

    node ntemp;
    int min;
    list_item<edge> it, minit;
    edge e;

    Array<node> anB(B.size() + 1);
    Array<node> partitionOwners(B.size() + 1);

    Array<List<node> > partitionMembers(B.size() + 1);

    List<node> newA;
    List<node> temp, temp2;
    List<node> newAA;

    List<edge> elist, elist2;

    NodeArray naiB(G);
    NodeArray naiA(G);

    if (wolfDebug == 1) cout << "\n\nWOLF PH1 STARTS\n---------------------\n";

    i = 0;
    for (auto const &nodeTemp : A) {
        naiA[nodeTemp] = i++;
    }

    if (wolfDebug == 1) {
        cout << "A:\n";
        i = 0;
        for (auto const &nodeTemp : A) { cout << i << "\t" << nodeTemp.ToString() << "\n"; }
        cout << "naiA:\n";
        for (auto const &nodeTemp : A) { cout << "naiA[" << nodeTemp.ToString() << "]\t" << naiA[nodeTemp] << "\n"; }
    }

    i = 1;
    for (auto const &nodeTemp : B) {
        naiB[nodeTemp] = i;
        anB[i] = nodeTemp;
        i++;
    }

    if (wolfDebug == 0) {
        cout << "B:\n";
        i = 0;
        for (auto const &nodeTemp : B)
            cout << i << "\t" << nodeTemp.ToString() << "\n";
        cout << "naiB:\n";
        for (auto const &nodeTemp : B)
            cout << "naiB[" << nodeTemp.ToString() << "]\t" << naiB[nodeTemp] << "\n";
        cout << "anB:\n";
        for (i = 0; i < B.size() + 1; i++) cout << "anB[" << i << "]\t" << anB[i].ToString() << "\n";
    }
    partitionOwners = anB;


    for (auto const &nodeTemp : A) {
        elist = G.GetAdjEdges(nodeTemp);
        elist2.clear();
        while (elist.size() > 0) {
            min = B.size() * 2;
            for (list_item<edge> iter = elist.begin(); iter != elist.end(); iter++) {
                e = elist[iter];
                ntemp = G.target(e);

                if (naiB[ntemp] < min) {
                    min = naiB[ntemp];
                    minit = iter;
                }
            }
            e = elist[minit];
            elist.erase(minit);
            elist2.push_back(e);
        }
        elist = elist2;

        leftsum = 0;
        rightsum = 0;
        for (auto const &edgeTemp : elist) {
            rightsum += G[edgeTemp];
        }

        k = 0;

        for (list_item<edge> iter = elist.begin(); iter != elist.end(); iter++) {
            e = *iter;

            k = naiB[G.target(e)] - 1;

            rightsum -= G[e];
            if (leftsum >= rightsum) {
                break;
            }

            leftsum += G[e];
            if (/*std::next(iter) &&*/ naiB[G.target(e)] + 1 == naiB[G.target(elist[std::next(iter)])]) {
                neighbourWeight = G[elist[std::next(iter)]];
            } else {
                neighbourWeight = 0;
            }
            if (leftsum >= rightsum - neighbourWeight) {
                k++;
                break;
            }
        }

        partitionMembers[k].push_back(nodeTemp);
    }

    if (wolfDebug == 1) {
        cout << "Partition Members\n";
    }
    for (i = 0; i < partitionMembers.size(); i++) {
        temp = partitionMembers[i];
        if (wolfDebug == 1) {
            cout << i << "\t=> ";
            temp.Print();
            cout << "\n";
        }
    }

    if (wolfDebug == 1) {
        j = 0;
        for (auto const &nodeTemp : A)
            cout << j++ << " => " << nodeTemp.ToString() << "\t";
    }


    if (wolfDebug == 1) cout << "0. Part -> ";
    for (auto const &nodeTemp : partitionMembers[0]) {
        //G[n] = naiA[n];
        if (wolfDebug == 1) cout << nodeTemp.ToString() << " ";
        newA.push_back(nodeTemp);
    }


    partitionCount = 0;
    for (i = 1; i < partitionMembers.size(); i++) {
        temp = partitionMembers[i];

        if (!temp.empty()) {
            partitionCount++;
        }
        if (justRunPhase1 == 1) {
        } else {
            if (wolfDebug == 1) {
                cout << "(" << i << ") Before: ";
                temp.Print();
                cout << "\n";
            }

            wolfPhase2(G, temp, partitionOwners[i], B);
            if (wolfDebug == 1) {
                cout << "(" << i << ") After: ";
                temp.Print();
                cout << "\n";
            }

            for (auto const &nodeTemp : temp) {
                cout << "";
                newA.push_back(nodeTemp);
            }
        }
    }

    return newA;
}

integer WolfImpl::weight(GRAPH<int, int> &G, node alt1, node alt2, node ust, List<node> alt) {
    integer sum = 0;
    int start = 0, end = 0, i;

    node n;
    List<edge> outedges = G.GetAdjEdges(ust);
    edge e;
    NodeArray alt_(G);

    /*
    if (alt1 == NULL) {
        return 0;
    }
    */
    i = 0;
    for (auto const &nodeTemp : alt) {
        alt_[n] = i;
        if (nodeTemp == alt1) {
            start = i;
        }
        if (nodeTemp == alt2) {
            end = i;
        }
        i++;
    }


    for (auto const &edgeTemp : outedges) {
        n = G.target(edgeTemp);
        if (alt_[n] >= start && alt_[n] <= end) {
            sum += (G[edgeTemp]);
        }
    }

    return sum;
}

int WolfImpl::getCrossings(GRAPH<int, int> &G, List<node> &A, List<node> &B) {
    List<node> A_, B_;

    GRAPH<int, int> G_;
    int i;
    node n, newn, tn, corn, cortn;
    edge e;
    Array<node> originalA(A.size());
    Array<node> originalB(B.size());
    Array<node> A__(A.size()), B__(B.size());
    NodeArray naiB(G);

    i = 0;
    for (auto const &nodeTemp : A) {
        newn = G_.new_node();
        A_.push_back(newn);
        A__[i] = newn;
        originalA[i] = nodeTemp;
        i++;
    }

    i = 0;
    for (auto const &nodeTemp : B) {
        newn = G_.new_node();
        B_.push_back(newn);
        B__[i] = newn;
        naiB[n] = i;
        originalB[i] = nodeTemp;
        i++;
    }

    for (i = 0; i < originalA.size(); i++) {
        n = originalA[i];
        corn = A__[i];
        for (auto const &e : G.GetAdjEdges(n)) {
            tn = G.target(e);
            cortn = B__[naiB[tn]];
            edge e2 = G_.new_edge(corn, cortn);
            // TODO G_[e2] = G[e];
        }
    }

    integer uv = crossingNumber(G_, A_, B_);
    A_.reverse();
    integer vu = crossingNumber(G_, A_, B_);

    if (uv < vu) {
        return -1;
    } else {
        return 1;
    }
}

void WolfImpl::merge(GRAPH<int, int> &G, List<node> &ptRow, List<node> &L, List<node> &R, node &owner,
                     List<node> &alt) {
    int i = 0, j = 0, k = 0;
    int rsize, lsize;
    integer ul, vl, ur, vr;
    node ownerNext;
    list_item<node> it;
    ptRow.clear();

    rsize = R.size();
    lsize = L.size();

    for (i = 0; i < lsize + rsize; i++) {
        if (k < rsize && j < lsize) {
            it = alt.Search(owner);
            it = std::next(it);

            /*
            if (it._Ptr)
                ownerNext = alt[it];
            else
                ownerNext = nil;
            */
            List<node> orderuv;
            orderuv.push_back(*L.GetItem(j));
            orderuv.push_back(*R.GetItem(k));

            int ordering = getCrossings(G, orderuv, alt);

            if (   /*( ur*vl ) <= ( vr*ul ) */ ordering == -1) {

                ptRow.push_back(L[L.GetItem(j)]);
                j++;
            } else {

                ptRow.push_back(R[R.GetItem(k)]);
                k++;
            }

        } else if (k >= rsize && j < lsize) {
            ptRow.push_back(L[L.GetItem(j)]);
            j++;

        } else if (j >= lsize && k < rsize) {
            ptRow.push_back(R[R.GetItem(k)]);
            k++;
        }

    }

}

void WolfImpl::wolfPhase2(GRAPH<int, int> &G, List<node> &ptRow, node &owner, List<node> alt) {
    int size = ptRow.size();
    int half = (int) size / 2;

    if (ptRow.size() == 1 || ptRow.size() == 0) {
        return;
    } else {
        auto middle = std::next(ptRow.begin(), ptRow.size() / 2);
        List<node> R(ptRow.begin(), middle);
        List<node> L(middle, ptRow.end());
        wolfPhase2(G, L, owner, alt);
        wolfPhase2(G, R, owner, alt);
        merge(G, ptRow, L, R, owner, alt);
    }
}

integer WolfImpl::crossingNumber(Matrix<int> &m) {
    integer crossingCount = 0, temp;
    int i, j;
    int col, row;
    col = m.dim2();
    row = m.dim1();
    double temp2;
    Matrix<int> mc(row, col);

    for (i = 0; i < row; i++) {
        mc(i, col - 1) = 0.0;
    }

    for (i = 0; i < col; i++) {
        mc(0, i) = 0.0;
    }

    double areaA, areaB, areaC;
    for (i = 1; i <= row - 1; i++) {
        for (j = col - 2; j >= 0; j--) {
            //mc(i,j) = m(i-1,j+1) + mc(i,j+1) + mc(i-1,j);
            areaA = areaB = areaC = 0.0;
            areaA = mc(i, j + 1);
            areaB = mc(i - 1, j);
            areaC = mc(i - 1, j + 1);
            temp2 = m(i - 1, j + 1);
            mc(i, j) = (areaB - areaC) + (areaA - areaC) + areaC + temp2;
            temp = mc(i, j) * m(i, j);
            crossingCount += (temp);

        }
    }

    return crossingCount;
}

integer WolfImpl::crossingNumber(GRAPH<int, int> &G, List<node> &A, List<node> &B) {
    Matrix<int> m = GraphToMatrix(G, A, B, true);
    return crossingNumber(m);
}

void WolfImpl::MatrixToGraph(GRAPH<int, int> &G, List<node> &A, List<node> &B, Matrix<int> &m, bool weighted) {
    int i, j;
    int k;
    int row = m.dim1(), col = m.dim2();
    Array<node> A1(row), B1(col);
    edge e;
    node sn, tn;
    A.clear();
    B.clear();
    G.clear();
    weighted = true;

    for (i = 0; i < row; i++) {
        sn = G.new_node();
        A1[i] = sn;
        A.push_back(sn);
    }

    for (j = 0; j < col; j++) {
        tn = G.new_node();
        B1[j] = tn;
        B.push_back(tn);
    }

    if (weighted) {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if ((int) m(i, j) != 0) {
                    e = G.new_edge(A1[i], B1[j], (int) m(i, j));
                    G[e] = (int) m(i, j);
                }
            }
        }
    } else {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                for (k = 0; k < (int) m(i, j); k++) {
                    e = G.new_edge(A1[i], B1[j]);
                    G[e] = 0;
                }
            }
        }
    }
}

Matrix<int> WolfImpl::GraphToMatrix(GRAPH<int, int> &G, List<node> A, List<node> B, bool weighted) {
    int i, j;
    int row = A.size(), col = B.size();
    Matrix<int> m(row, col);
    NodeArray A1(G);
    NodeArray B1(G);
    weighted = true;
    edge e;
    node n;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            m(i, j) = (double) 0;
        }
    }
    i = 0;
    for (auto const &nodeTemp : A) {
        A1[nodeTemp] = i;
        i++;
    }

    i = 0;
    for (auto const &nodeTemp : B) {
        B1[nodeTemp] = i;
        i++;
    }

    node sn, tn;
    for (auto const &edgeTemp : G.GetAllEdges()) {
        sn = G.source(edgeTemp);
        tn = G.target(edgeTemp);

        if (weighted) {
            m(A1[sn], B1[tn]) = G[edgeTemp];
        } else {
            m(A1[sn], B1[tn]) = m(A1[sn], B1[tn]) + (double) 1.0;
        }
    }

    return m;
}