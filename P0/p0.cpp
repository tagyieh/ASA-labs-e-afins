#include <iostream>
using namespace std;

void getFriends(int people, int relationships) {
    int network[people][people] = {}, friends[people][people] = {}, histogram1[people]={}, histogram2[people]={};
    int total, person, index, _friend, index1;
    
    //Read relationships and add them to network and friends
    for (index=0;index<relationships;index++) {
        cin >> person >> _friend;
        network[person-1][person-1] += 1;
        friends[person-1][_friend-1] += 1;
        for (index1=0;index1<people;index1++) {
            if (index1!=person-1 && friends[index1][_friend-1]!=0) {
                network[person-1][index1]+=1;
                network[index1][person-1]+=1;
            }
        } 
    }

    //Calculate friends per person
    for (index=0;index<people;index++) {
        total = 0;
        for (index1=0;index1<people;index1++) {
            if (friends[index][index1]!=0) total++;
        }
        histogram1[total]++;
    }
    
    //Print Histogram1
    cout << "Histograma1" << endl;
    for (index=0;index<people;index++) {
        cout<<histogram1[index]<<endl;
    }

    //Calculate how many people befriended each person
    for (index=0;index<people;index++) {
        total = 0;
        for (index1=0;index1<people;index1++) {
            if (friends[index1][index]!=0) total++;
        }
        histogram2[total]++;
    }

    //Print Histogram2
    cout << "Histograma2" << endl;
    for (index=0;index<people;index++) 
        cout << histogram2[index]<<endl;

    //Print Network
    for (index=0;index<people;index++) {
        for (_friend=0;_friend<people;_friend++) {
            cout << network[index][_friend] << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
    int people, relationships;
    char ignore;
    cin >> people >> ignore >> relationships;
    getFriends(people, relationships);
    return 0;
}
