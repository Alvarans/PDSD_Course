#include <iostream>
#include "SetLab1_10.h"
#include "SetLab3_Kostiuk.h"
#include "SetLab4_Kostiuk.h"
#include "SetLab5_Kostiuk.h"
#include "Set_Map.h"
#include "chrono"


using namespace std;

int main()
{
    // Set creation
    int N;
    cout << "How many elements do you prefer(>=1000)?";
    cin >> N;
    while (N < 1000) {
        if (N < 0)
            cout << "It's negative set power. Please, write correct elements: " << endl;
        else
            cout << "It's so small set power. Please, write correct elements: " << endl;
        cin >> N;
    }
    auto begin_CreateSet = std::chrono::high_resolution_clock::now();
    Set* firstSet = createSet(N, 1, N * 2, 1);
    auto end_CreateSet = std::chrono::high_resolution_clock::now();
    auto time_took_CreateSet = std::chrono::duration_cast<std::chrono::duration < double>>(end_CreateSet - begin_CreateSet);
    Set* secondSet = createSet(N, 1, N * 4, 2);
    auto begin_CreateCl = std::chrono::high_resolution_clock::now();
    SetList firstCl = *new SetList;
    SetList secondCl = *new SetList;
    firstCl.createSetCl(N, 1, N * 2, 1);
    auto end_CreateCl = std::chrono::high_resolution_clock::now();
    auto time_took_CreateCl = std::chrono::duration_cast<std::chrono::duration < double>>(end_CreateCl - begin_CreateCl);
    secondCl.createSetCl(N, 1, N * 4, 2);
    auto begin_CreateList = std::chrono::high_resolution_clock::now();
    ListClass firstList;
    ListClass secondList;
    firstList.createSetCl(N, 1, N * 2, 1);
    auto end_CreateList = std::chrono::high_resolution_clock::now();
    auto time_took_CreateList = std::chrono::duration_cast<std::chrono::duration < double>>(end_CreateList - begin_CreateList);
    secondList.createSetCl(N, 1, N * 4, 2);
    auto begin_CreateSetCl = std::chrono::high_resolution_clock::now();
    SetClass A;
    SetClass B;
    A.createSetCl(N, 1, N*2, 1);
    auto end_CreateSetCl = std::chrono::high_resolution_clock::now();
    auto time_took_CreateSetCl = std::chrono::duration_cast<std::chrono::duration < double>>(end_CreateSetCl - begin_CreateSetCl);
    B.createSetCl(N, 1, N*4, 2);

    //Power of sets
    auto begin_PowerSet = std::chrono::high_resolution_clock::now();
    setPower(firstSet);
    auto end_PowerSet = std::chrono::high_resolution_clock::now();
    auto time_took_PowerSet = std::chrono::duration_cast<std::chrono::duration < double>>(end_PowerSet - begin_PowerSet);
    auto begin_PowerCl = std::chrono::high_resolution_clock::now();
    firstCl.setPowerCl(firstCl.root);
    auto end_PowerCl = std::chrono::high_resolution_clock::now();
    auto time_took_PowerCl = std::chrono::duration_cast<std::chrono::duration < double>>(end_PowerCl - begin_PowerCl);
    auto begin_PowerList = std::chrono::high_resolution_clock::now();
    firstList.setPowerCl();
    auto end_PowerList = std::chrono::high_resolution_clock::now();
    auto time_took_PowerList = std::chrono::duration_cast<std::chrono::duration < double>>(end_PowerList - begin_PowerList);
    auto begin_PowerSetCl = std::chrono::high_resolution_clock::now();
    A.setPowerCl();
    auto end_PowerSetCl = std::chrono::high_resolution_clock::now();
    auto time_took_PowerSetCl = std::chrono::duration_cast<std::chrono::duration < double>>(end_PowerCl - begin_PowerCl);

    //Subbing set A - A
    auto begin_isSubSetAA = std::chrono::high_resolution_clock::now();
    isSubSet(firstSet, firstSet);
    auto end_isSubSetAA = std::chrono::high_resolution_clock::now();
    auto time_took_isSubSetAA = std::chrono::duration_cast<std::chrono::duration < double>>(end_isSubSetAA - begin_isSubSetAA);
    auto begin_isSubClassAA = std::chrono::high_resolution_clock::now();
    firstCl.isSubSetCl(firstCl.root, secondCl.root);
    auto end_isSubClassAA = std::chrono::high_resolution_clock::now();
    auto time_took_isSubClassAA = std::chrono::duration_cast<std::chrono::duration < double>>(end_isSubClassAA - begin_isSubClassAA);
    auto begin_isSubListAA = std::chrono::high_resolution_clock::now();
    firstList.isSubSetCl(firstList, firstList);
    auto end_isSubListAA = std::chrono::high_resolution_clock::now();
    auto time_took_isSubListAA = std::chrono::duration_cast<std::chrono::duration < double>>(end_isSubListAA - begin_isSubListAA);
    auto begin_isSubSetClAA = std::chrono::high_resolution_clock::now();
    A.isSubSetCl(A, A);
    auto end_isSubSetClAA = std::chrono::high_resolution_clock::now();
    auto time_took_isSubSetClAA = std::chrono::duration_cast<std::chrono::duration < double>>(end_isSubSetClAA - begin_isSubSetClAA);

    //Subbing set A - B
    auto begin_isSubSetAB = std::chrono::high_resolution_clock::now();
    isSubSet(firstSet, secondSet);
    auto end_isSubSetAB = std::chrono::high_resolution_clock::now();
    auto time_took_isSubSetAB = std::chrono::duration_cast<std::chrono::duration < double>>(end_isSubSetAB - begin_isSubSetAB);
    auto begin_isSubClassAB = std::chrono::high_resolution_clock::now();
    firstCl.isSubSetCl(firstCl.root, secondCl.root);
    auto end_isSubClassAB = std::chrono::high_resolution_clock::now();
    auto time_took_isSubClassAB = std::chrono::duration_cast<std::chrono::duration < double>>(end_isSubClassAB - begin_isSubClassAB);
    auto begin_isSubListAB = std::chrono::high_resolution_clock::now();
    firstList.isSubSetCl(firstList, secondList);
    auto end_isSubListAB = std::chrono::high_resolution_clock::now();
    auto time_took_isSubListAB = std::chrono::duration_cast<std::chrono::duration < double>>(end_isSubListAB - begin_isSubListAB);
    auto begin_isSubSetClAB = std::chrono::high_resolution_clock::now();
    A.isSubSetCl(A, B);
    auto end_isSubSetClAB = std::chrono::high_resolution_clock::now();
    auto time_took_isSubSetClAB = std::chrono::duration_cast<std::chrono::duration < double>>(end_isSubSetClAB - begin_isSubSetClAB);

    //Equal set A - A
    auto begin_isEqualSetAA = std::chrono::high_resolution_clock::now();
    setsIsEqual(firstSet, firstSet);
    auto end_isEqualSetAA = std::chrono::high_resolution_clock::now();
    auto time_took_isEqualSetAA = std::chrono::duration_cast<std::chrono::duration < double>>(end_isEqualSetAA - begin_isEqualSetAA);
    auto begin_isEqualClassAA = std::chrono::high_resolution_clock::now();
    firstCl.setsIsEqualCl(firstCl.root, firstCl.root);
    auto end_isEqualClassAA = std::chrono::high_resolution_clock::now();
    auto time_took_isEqualClassAA = std::chrono::duration_cast<std::chrono::duration < double>>(end_isEqualClassAA - begin_isEqualClassAA);
    auto begin_isEqualListAA = std::chrono::high_resolution_clock::now();
    firstList.setsIsEqualCl(firstList, firstList);
    auto end_isEqualListAA = std::chrono::high_resolution_clock::now();
    auto time_took_isEqualListAA = std::chrono::duration_cast<std::chrono::duration < double>>(end_isEqualListAA - begin_isEqualListAA);
    auto begin_isEqualClAA = std::chrono::high_resolution_clock::now();
    A.setsIsEqualCl(A, A);
    auto end_isEqualClAA = std::chrono::high_resolution_clock::now();
    auto time_took_isEqualSetClAA = std::chrono::duration_cast<std::chrono::duration < double>>(end_isEqualClAA - begin_isEqualClAA);

    //Equal set A - B
    auto begin_isEqualSetAB = std::chrono::high_resolution_clock::now();
    setsIsEqual(firstSet, secondSet);
    auto end_isEqualSetAB = std::chrono::high_resolution_clock::now();
    auto time_took_isEqualSetAB = std::chrono::duration_cast<std::chrono::duration < double>>(end_isEqualSetAB - begin_isEqualSetAB);
    auto begin_isEqualClassAB = std::chrono::high_resolution_clock::now();
    firstCl.setsIsEqualCl(firstCl.root, secondCl.root);
    auto end_isEqualClassAB = std::chrono::high_resolution_clock::now();
    auto time_took_isEqualClassAB = std::chrono::duration_cast<std::chrono::duration < double>>(end_isEqualClassAB - begin_isEqualClassAB);
    auto begin_isEqualListAB = std::chrono::high_resolution_clock::now();
    firstList.setsIsEqualCl(firstList, secondList);
    auto end_isEqualListAB = std::chrono::high_resolution_clock::now();
    auto time_took_isEqualListAB = std::chrono::duration_cast<std::chrono::duration < double>>(end_isEqualListAB - begin_isEqualListAB);
    auto begin_isEqualClAB = std::chrono::high_resolution_clock::now();
    A.setsIsEqualCl(A, B);
    auto end_isEqualClAB = std::chrono::high_resolution_clock::now();
    auto time_took_isEqualSetClAB = std::chrono::duration_cast<std::chrono::duration < double>>(end_isEqualClAB - begin_isEqualClAB);

    //Combine sets A - B
    auto begin_CombineSet = std::chrono::high_resolution_clock::now();
    Set* combineSet = combineTwoSets(firstSet, secondSet);
    auto end_CombineSet = std::chrono::high_resolution_clock::now();
    auto time_took_CombineSet = std::chrono::duration_cast<std::chrono::duration < double>>(end_CombineSet - begin_CombineSet);
    auto begin_CombineCl = std::chrono::high_resolution_clock::now();
    SetList combineClass = *new SetList;
    combineClass.combineTwoSetsCl(firstCl.root, secondCl.root);
    auto end_CombineCl = std::chrono::high_resolution_clock::now();
    auto time_took_CombineClAB = std::chrono::duration_cast<std::chrono::duration < double>>(end_CombineCl - begin_CombineCl);
    auto begin_CombineList = std::chrono::high_resolution_clock::now();
    ListClass combineList;
    combineList.combineTwoSetsCl(firstList, secondList);
    auto end_CombineList = std::chrono::high_resolution_clock::now();
    auto time_took_CombineList = std::chrono::duration_cast<std::chrono::duration < double>>(end_CombineList - begin_CombineList);
    auto begin_CombineSetCl = std::chrono::high_resolution_clock::now();
    SetClass combainedSet = combainedSet.comnineTwoSetsCl(A, B);
    auto end_CombineSetCl = std::chrono::high_resolution_clock::now();
    auto time_took_CombineSetCl = std::chrono::duration_cast<std::chrono::duration < double>>(end_CombineSetCl - begin_CombineSetCl);

    //Intersections sets A - B
    auto begin_intersectionSet = std::chrono::high_resolution_clock::now();
    Set* intersectionSet = intersectionofSets(firstSet, secondSet);
    auto end_intersectionSet = std::chrono::high_resolution_clock::now();
    auto time_took_intersectionSet = std::chrono::duration_cast<std::chrono::duration < double>>(end_intersectionSet - begin_intersectionSet);
    auto begin_intersectionCl = std::chrono::high_resolution_clock::now();
    SetList intersectionClass = *new SetList;
    combineClass.intersectionofSetsCl(firstCl.root, secondCl.root);
    auto end_intersectionCl = std::chrono::high_resolution_clock::now();
    auto time_took_intersectionCl = std::chrono::duration_cast<std::chrono::duration < double>>(end_intersectionCl - begin_intersectionCl);
    auto begin_intersectionList = std::chrono::high_resolution_clock::now();
    ListClass intersectionList;
    intersectionList.intersectionofSetsCl(firstList, secondList);
    auto end_intersectionList = std::chrono::high_resolution_clock::now();
    auto time_took_intersectionList = std::chrono::duration_cast<std::chrono::duration < double>>(end_intersectionList - begin_intersectionList);
    auto begin_intersectionSetCl = std::chrono::high_resolution_clock::now();
    SetClass intersectionSetCl = intersectionSetCl.intersectionofSetsCl(A, B);
    auto end_intersectionSetCl = std::chrono::high_resolution_clock::now();
    auto time_took_intersectionSetCl = std::chrono::duration_cast<std::chrono::duration < double>>(end_intersectionSetCl - begin_intersectionSetCl);

    //Difference between sets A - B
    auto begin_differenceSet = std::chrono::high_resolution_clock::now();
    Set* differenceSet = setDifference(firstSet, secondSet);
    auto end_differenceSet = std::chrono::high_resolution_clock::now();
    auto time_took_differenceSet = std::chrono::duration_cast<std::chrono::duration < double>>(end_differenceSet - begin_differenceSet);
    auto begin_differenceCl = std::chrono::high_resolution_clock::now();
    SetList differenceClass = *new SetList;
    differenceClass.setDifferenceCl(firstCl.root, secondCl.root);
    auto end_differenceCl = std::chrono::high_resolution_clock::now();
    auto time_took_differenceCl = std::chrono::duration_cast<std::chrono::duration < double>>(end_differenceCl - begin_differenceCl);
    auto begin_differenceList = std::chrono::high_resolution_clock::now();
    ListClass differenceList;
    differenceList.setDifferenceCl(firstList, secondList);
    auto end_differenceList = std::chrono::high_resolution_clock::now();
    auto time_took_differenceList = std::chrono::duration_cast<std::chrono::duration < double>>(end_differenceList - begin_differenceList);
    auto begin_differenceSetCl = std::chrono::high_resolution_clock::now();
    SetClass differenceSetCl = differenceSetCl.setDifferenceCl(A, B);
    auto end_differenceSetCl = std::chrono::high_resolution_clock::now();
    auto time_took_differenceSetCl = std::chrono::duration_cast<std::chrono::duration < double>>(end_differenceSetCl - begin_differenceSetCl);

    //Symmetric difference between sets A - B
    auto begin_symdifferenceSet = std::chrono::high_resolution_clock::now();
    Set* symdifferenceSet = symmetricalDifference(firstSet, secondSet);
    auto end_symdifferenceSet = std::chrono::high_resolution_clock::now();
    auto time_took_symdifferenceSet = std::chrono::duration_cast<std::chrono::duration < double>>(end_symdifferenceSet - begin_symdifferenceSet);
    auto begin_symdifferenceCl = std::chrono::high_resolution_clock::now();
    SetList symdifferenceClass = *new SetList;
    symdifferenceClass.symmetricalDifferenceCl(firstCl.root, secondCl.root);
    auto end_symdifferenceCl = std::chrono::high_resolution_clock::now();
    auto time_took_symdifferenceCl = std::chrono::duration_cast<std::chrono::duration < double>>(end_symdifferenceCl - begin_symdifferenceCl);
    auto begin_symdifferenceList = std::chrono::high_resolution_clock::now();
    ListClass symdifferenceList;
    symdifferenceList.symmetricalDifferenceCl(firstList, secondList);
    auto end_symdifferenceList = std::chrono::high_resolution_clock::now();
    auto time_took_symdifferenceList = std::chrono::duration_cast<std::chrono::duration < double>>(end_symdifferenceList - begin_symdifferenceList);
    auto begin_symdifferenceSetCl = std::chrono::high_resolution_clock::now();
    SetClass symdifference = symdifference.symmetricalDifferenceCl(combainedSet, intersectionSetCl);
    auto end_symdifferenceSetCl = std::chrono::high_resolution_clock::now();
    auto time_took_symdifferenceSetCl = std::chrono::duration_cast<std::chrono::duration < double>>(end_symdifferenceSetCl - begin_symdifferenceSetCl);
    auto begin_createMap = std::chrono::high_resolution_clock::now();
    MapClass AMap, BMap;
    AMap.createSetMap(N, 1, N * 2, 1);
    auto end_createMap = std::chrono::high_resolution_clock::now();
    auto time_took_createMap = std::chrono::duration_cast<std::chrono::duration < double>>(end_createMap - begin_createMap);
    BMap.createSetMap(N, 1, N * 4, 2);
    auto begin_mapPower = std::chrono::high_resolution_clock::now();
    auto end_mapPower = std::chrono::high_resolution_clock::now();
    auto time_took_mapPower = std::chrono::duration_cast<std::chrono::duration < double>>(end_mapPower - begin_mapPower);
    auto begin_subSetMapAB = std::chrono::high_resolution_clock::now();
    AMap.isSubSetMap(AMap, BMap);
    auto end_subSetMapAB = std::chrono::high_resolution_clock::now();
    auto time_took_subSetMapAB = std::chrono::duration_cast<std::chrono::duration < double>>(end_subSetMapAB - begin_subSetMapAB);
    auto begin_subSetMapAA = std::chrono::high_resolution_clock::now();
    AMap.isSubSetMap(AMap, AMap);
    auto end_subSetMapAA = std::chrono::high_resolution_clock::now();
    auto time_took_subSetMapAA = std::chrono::duration_cast<std::chrono::duration < double>>(end_subSetMapAA - begin_subSetMapAA);
    auto begin_equalSetMapAB = std::chrono::high_resolution_clock::now();
    AMap.setsIsEqualMap(AMap, BMap);
    auto end_equalSetMapAB = std::chrono::high_resolution_clock::now();
    auto time_took_equalSetMapAB = std::chrono::duration_cast<std::chrono::duration < double>>(end_equalSetMapAB - begin_equalSetMapAB);
    auto begin_equalSetMapAA = std::chrono::high_resolution_clock::now();
    AMap.setsIsEqualMap(AMap, AMap);
    auto end_equalSetMapAA = std::chrono::high_resolution_clock::now();
    auto time_took_equalSetMapAA = std::chrono::duration_cast<std::chrono::duration < double>>(end_equalSetMapAA - begin_equalSetMapAA);
    auto begin_combainedMap = std::chrono::high_resolution_clock::now();
    MapClass combainedMap = combainedMap.comnineTwoSetsMap(AMap, BMap);
    auto end_combainedMap = std::chrono::high_resolution_clock::now();
    auto time_took_combainedMap = std::chrono::duration_cast<std::chrono::duration < double>>(end_combainedMap - begin_combainedMap);
    auto begin_intersectionMap = std::chrono::high_resolution_clock::now();
    MapClass intersectionMap = intersectionMap.intersectionofSetsMap(AMap, BMap);
    auto end_intersectionMap = std::chrono::high_resolution_clock::now();
    auto time_took_intersectionMap = std::chrono::duration_cast<std::chrono::duration < double>>(end_intersectionMap - begin_intersectionMap);
    auto begin_differenceABMap = std::chrono::high_resolution_clock::now();
    MapClass differenceABMap = differenceABMap.setDifferenceMap(AMap, BMap);
    auto end_differenceABMap = std::chrono::high_resolution_clock::now();
    auto time_took_differenceABMap = std::chrono::duration_cast<std::chrono::duration < double>>(end_differenceABMap - begin_differenceABMap);
    auto begin_symdifferenceMap = std::chrono::high_resolution_clock::now();
    MapClass symdifferenceMap = symdifferenceMap.symmetricalDifferenceMap(combainedMap, intersectionMap);
    auto end_symdifferenceMap = std::chrono::high_resolution_clock::now();
    auto time_took_symdifferenceMap = std::chrono::duration_cast<std::chrono::duration < double>>(end_symdifferenceMap - begin_symdifferenceMap);
    AMap.deleteSetMap();
    BMap.deleteSetMap();
    combainedMap.deleteSetMap();
    intersectionMap.deleteSetMap();
    differenceABMap.deleteSetMap();
    symdifferenceMap.deleteSetMap();
    cout << "\t\t\t\t\t\t\t Set's operations \n";
    cout << "\t\t\tStruct\t\t\tSetClass\t\tList\t\t\tSet\t\t\tMap\n";
    cout << "Set's creating: \t" << to_string(time_took_CreateSet.count()*10000) << "\t\t" << to_string(time_took_CreateCl.count() * 10000) << "\t\t" << to_string(time_took_CreateList.count() * 10000) << "\t\t" << to_string(time_took_CreateSetCl.count() * 10000) << "\t\t" << to_string(time_took_createMap.count() * 10000) << endl;
    cout << "Set power: \t\t" << to_string(time_took_PowerSet.count() * 10000) << "\t\t" << to_string(time_took_PowerCl.count() * 10000) << "\t\t" << to_string(time_took_PowerList.count() * 10000) << "\t\t" << to_string(time_took_PowerSetCl.count() * 10000)<< "\t\t" << to_string(time_took_mapPower.count() * 10000) << endl;
    cout << "isSubSet A - A: \t" << to_string(time_took_isSubSetAA.count() * 10000) << "\t\t" << to_string(time_took_isSubClassAA.count() * 10000) << "\t\t" << to_string(time_took_isSubListAA.count() * 10000) << "\t\t" << to_string(time_took_isSubSetClAA.count() * 10000) << "\t\t" << to_string(time_took_subSetMapAA.count() * 10000) << endl;
    cout << "isSubSet A - B: \t" << to_string(time_took_isSubSetAB.count() * 10000) << "\t\t" << to_string(time_took_isSubClassAB.count() * 10000) << "\t\t" << to_string(time_took_isSubListAB.count() * 10000) << "\t\t" << to_string(time_took_isSubSetClAB.count() * 10000) << "\t\t" << to_string(time_took_subSetMapAB.count() * 10000) << endl;
    cout << "isEqual A - A: \t\t" << to_string(time_took_isEqualSetAA.count() * 10000) << "\t\t" << to_string(time_took_isEqualClassAA.count() * 10000) << "\t\t" << to_string(time_took_isEqualListAA.count() * 10000) << "\t\t" << to_string(time_took_isEqualSetClAA.count() * 10000) << "\t\t" << to_string(time_took_equalSetMapAA.count() * 10000) << endl;
    cout << "isEqual A - B: \t\t" << to_string(time_took_isEqualSetAB.count() * 10000) << "\t\t" << to_string(time_took_isEqualClassAB.count() * 10000) << "\t\t" << to_string(time_took_isEqualListAB.count() * 10000) << "\t\t" << to_string(time_took_isEqualSetClAB.count() * 10000) << "\t\t" << to_string(time_took_equalSetMapAB.count() * 10000) << endl;
    cout << "Combine A B sets: \t" << to_string(time_took_CombineSet.count() * 10000) << "\t\t" << to_string(time_took_CombineSet.count() * 10000) << "\t\t" << to_string(time_took_CombineSet.count() * 10000) << "\t\t" << to_string(time_took_CombineSet.count() * 10000) << "\t\t" << to_string(time_took_combainedMap.count() * 10000) << endl;
    cout << "Intersection A B sets: \t" << to_string(time_took_intersectionSet.count() * 10000) << "\t\t" << to_string(time_took_intersectionCl.count() * 10000) << "\t\t" << to_string(time_took_intersectionList.count() * 10000) << "\t\t" << to_string(time_took_intersectionSetCl.count() * 10000) << "\t\t" << to_string(time_took_intersectionMap.count() * 10000) << endl;
    cout << "Difference A B sets: \t" << to_string(time_took_differenceSet.count() * 10000) << "\t\t" << to_string(time_took_differenceCl.count() * 10000) << "\t\t" << to_string(time_took_differenceList.count() * 10000) << "\t\t" << to_string(time_took_differenceSetCl.count() * 10000) << "\t\t" << to_string(time_took_differenceABMap.count() * 10000) << endl;
    cout << "Symmetric difference: \t" << to_string(time_took_symdifferenceSet.count() * 10000) << "\t\t" << to_string(time_took_symdifferenceCl.count() * 10000) << "\t\t" << to_string(time_took_symdifferenceList.count() * 10000) << "\t\t" << to_string(time_took_symdifferenceSetCl.count() * 10000) << "\t\t" << to_string(time_took_symdifferenceMap.count() * 10000) << endl;
    
}
