// Can only solvable if inversion is even

// Complete the larrysArray function below.
// https://www.cs.bham.ac.uk/~mdr/teaching/modules04/java2/TilesSolvability.html
string larrysArray(vector<int> A) {
    int inversions = 0;
    for(int i = 0 ; i < A.size(); i++)
        for(int j = i+1; j < A.size(); j++)
            if(A[i] > A[j])
                inversions++;
    return (inversions%2)?"NO":"YES";
}
