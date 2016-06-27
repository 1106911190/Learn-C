#include<iostream>
#include<time.h>

using namespace std;

class Cell{
public:
	int data;
	Cell(int data){
		this->data=data;
	}
};

class Grid{
public:
	// ��������
	Cell *rows[9][9];
	// ��������
	Cell *columns[9][9];
	// �����Ĺ���
	Cell *blocks[9][9];

	Grid(int datas[9][9]){
		this->SetDatas(datas);
	}

	// ��������������
	void SetDatas(int datas[9][9]){
		for(int r=0;r<9;r++){
			for(int c=0;c<9;c++){
				Cell* cell=new Cell(datas[r][c]);
				rows[r][c]=cell;
				columns[c][r]=cell;

				int b=(r/3)*3+c/3;
				int i=(r%3)*3+c%3;
				blocks[b][i]=cell;
			}
		}
	}

	// ���������е�����˳��
	void MessNumbers(){
		int numberMap[9];
		bool numberUsed[9]={false,false,false,false,false,false,false,false,false};
		int t;
		srand((int)time(0));
		for(int i=0;i<9;i++){
			do{
				t=rand()%9;
			}while(numberUsed[t]);
			numberUsed[t]=true;
			numberMap[i]=t;
		}
		for(int r=0;r<9;r++){
			for(int c=0;c<9;c++){
				Cell* cell=rows[r][c];
				cell->data = numberMap[cell->data-1]+1;
			}
		}
	}

	// ��ת��������
	void ReflactGrid(){
	}

	// ��ת��������
	void RotateGrid(){
	}

	// �����������
	void OutputGrid(){
		for(int r=0;r<9;r++){
			if(r%3==0){
				cout<<" ------- ------- -------"<<endl;
			}
			for(int c=0;c<9;c++){
				if(c%3==0){
					cout<<"| ";
				}
				Cell* cell=this->rows[r][c];
				cout<<cell->data<<' ';
			}
			cout<<'|'<<endl;
		}
		cout<<" ------- ------- -------"<<endl;
	}
};

int main(){
	int basicDatas[9][9]={
		{1, 2, 3, 4, 5, 6, 7, 8, 9},
		{4, 5, 6, 7, 8, 9, 1, 2, 3},
		{7, 8, 9, 1, 2, 3, 4, 5, 6},
		{2, 3, 4, 5, 6, 7, 8, 9, 1},
		{5, 6, 7, 8, 9, 1, 2, 3, 4},
		{8, 9, 1, 2, 3, 4, 5, 6, 7},
		{3, 4, 5, 6, 7, 8, 9, 1, 2},
		{6, 7, 8, 9, 1, 2, 3, 4, 5},
		{9, 1, 2, 3, 4, 5, 6, 7, 8}
	};
	Grid* grid=new Grid(basicDatas);
	cout<<endl;
	grid->OutputGrid();
	grid->MessNumbers();
	cout<<endl;
	grid->OutputGrid();

	system("pause");
	return 0;
}
