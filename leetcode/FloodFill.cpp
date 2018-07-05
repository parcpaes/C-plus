//733
#include <bits/stdc++.h>

using namespace std;
int dx[] = {1,0,-1,0};
int dy[] = {0,1, 0,-1};
void dfsfill(int x, int y, vector<vector<int>>& image,int replace, int newColor){
	if(x<0 || x >= image.size() || y<0 || y >= image[0].size()) return;
	if(image[x][y]!=replace) return;
	image[x][y]=newColor;	
	for(int i=0;i<4;i++){
		dfsfill(x+dx[i],y+dy[i],image,replace,newColor);
	}
	return;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
	if(image[sr][sc] == newColor) return image;
	dfsfill(sr,sc,image,image[sr][sc],newColor);
	return image;
}

int main(){
	vector<vector<int>> image{
		 					  {0},
		 					 };    
	floodFill(image,0,0,1);
	for(int i=0;i<image.size();i++){
		for(int j=0;j<image[0].size();j++){
			cout << image[i][j] << " " ;
		}
		cout << "\n";
	}
	return 0;
}