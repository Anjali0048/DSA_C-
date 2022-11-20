#include<iostream>
#include<vector>
using namespace std;

// row wise sum
void printRowWiseSum(int arr[][3],int row, int col){

    for(int row=0; row<3; row++){
        int sum = 0;
        for(int col=0; col<3; col++){
            sum += arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

// col wise sum
void printColWiseSum(int arr[][3],int row, int col){

    for(int col=0; col<3; col++){
        int sum = 0;
        for(int row=0; row<3; row++){
            sum += arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here
    vector<int> ans;

    for(int col=0; col<mCols; col++){

        if(col & 1){   //if(col % 2 != 0)
            for(int row=nRows-1; row>=0; row--){
                // cout<<arr[row][col]<<" ";
                ans.push_back(arr[row][col]);
            }
        }

        else{    
            for(int row=0; row<nRows; row++){
                // cout<<arr[row][col]<<" ";
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {

    vector<int> ans;
    int row_start = 0, row_end = matrix.size()-1;
    int col_start = 0, col_end = matrix[0].size()-1;
    int count = 0;
    int total = (matrix.size())*(matrix[0].size());

    while(row_start <= row_end && col_start <= col_end  && count < total){

        for(int col=col_start; count < total && col<=col_end; col++){
            ans.push_back(matrix[row_start][col]);
            count++;
        }
        row_start++;

        for(int row=row_start; count < total &&  row<=row_end; row++){
            ans.push_back(matrix[row][col_end]);
            count++;
        }
        col_end--;

        for(int col=col_end; count < total &&  col>=col_start; col--){
            ans.push_back(matrix[row_end][col]);
            count++;
        }
        row_end--;

        for(int row=row_end; count < total &&  row>=row_start; row--){
            ans.push_back(matrix[row][col_start]);
            count++;
        }
        col_start++;

    }  
    return ans;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int i = 0;
    int j = col - 1;
    while(i<row && j>=0){
        
        if(matrix[i][j]==target){
            return 1;
        }
        if(matrix[i][j]<target){
            i++;
        }
        else{
            j--;
        }
    
    }
    return 0;
}

bool BinarySearchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = row*col - 1;
    
       while(start <= end){
    
            int mid = start + (end-start)/2;
            int ele = matrix[mid/col][mid%col];
            
            if(ele==target){
                return 1;
            }
            if(ele<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        
        }
        return 0;
    }



int main(){

    int arr[3][3];
    cout<<"enter elements : "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }

    // printRowWiseSum(arr,3,3);
    // printColWiseSum(arr,3,3);


    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}