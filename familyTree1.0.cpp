#include<iostream>
#include<string>

using namespace std;

class Menber{
    public:
        string name;
        string ID;
        int age;
        char garden;
};

class Tree{
    public:
    Menber* data;
    Tree* child;
    Tree* borther;
    Tree* father;

    static Tree* createNode(string name,string ID,int age,char garden,Tree* father){
        Menber* newMenber=new Menber();
        Tree* newTree=new Tree();
        newMenber->name=name;
        newMenber->ID=ID;
        newMenber->age=age;
        newMenber->garden=garden;
        newTree->father=father;
        newTree->data=newMenber;
        return newTree;
    }   

    static Tree* createTree(){
        Tree* newTree=new Tree();
        Menber* dummyMenber=new Menber();
        newTree->data=dummyMenber;
        newTree->father=nullptr;
        newTree->borther=nullptr;
        newTree->child=nullptr;
        return newTree;
    }
    static int print(Tree* ancester,int n){
        if(ancester==nullptr){
            return 0;
        }
        for(int i=0;i<n*4;i++){
            cout<<" ";
        }
        cout<<ancester->data->name<<"\t"<<ancester->data->ID<<"\t"<<ancester->data->age<<"\t"<<ancester->data->garden<<endl;
        print(ancester->borther,n);
        print(ancester->child,n+1);
        return 1;
    }

    static Tree* find(Tree* ancester,string findName){
        if(ancester==nullptr){
            return nullptr;
        }
        if(ancester->data->name==findName){
            return ancester;
        }
        find(ancester->borther,findName);
        find(ancester->child,findName);
        return nullptr;
    }

    static int addMenber(Tree* ancester){
        cout<<"请输入被添加者父亲的姓名（如没有则输入无）"<<endl;
        string fatherName;
        cin>>fatherName;

        Tree* fatherNode;
        if(fatherName!="无"){
        fatherNode=find(ancester->child,fatherName);
        if(fatherNode==nullptr){
            return 0;
        }}else{
            fatherNode=ancester;
        }

        cout<<"请输入被添加者姓名"<<endl;
        string name;
        cin>>name;
        cout<<"请输入被添加者身份证号"<<endl;
        string ID;
        cin>>ID;
        cout<<"请输入被添加者性别"<<endl;
        char garden;
        cin>>garden;
        cout<<"请输入被添加者年龄"<<endl;
        int age;
        cin>>age;
        
       Tree* newMenber=createNode(name,ID,age,garden,fatherNode);

        if(fatherNode->child==nullptr){
            fatherNode->child=newMenber;
        }else{
            Tree* brotherMenber=fatherNode->child;
            while(brotherMenber!=nullptr){
                brotherMenber=brotherMenber->borther;
            }
            brotherMenber=newMenber;
        }
    
        cout<<"已完成添加"<<endl;
        return 1;
    }
};
void menu(){
    cout<<"1.建立族谱"<<endl;
    cout<<"2.添加成员"<<endl;
    cout<<"3.打印族谱"<<endl;
    cout<<"4.查找成员"<<endl;
    cout<<"5.退出"<<endl;
}

int main(){
    menu();
    int num=0;
    Tree* ancester=Tree::createTree();
    while(1){
    cout<<"请输入选项"<<endl;
    cin>>num;
    switch(num){
        case 2:{int flag=Tree::addMenber(ancester);
                if(flag==0){
                    cout<<"被添加人父亲不存在"<<endl;
                }else{
                    cout<<"添加成功"<<endl;
                }
                break;
    }
        case 3: {Tree::print(ancester->child,0);break;}
        case 4: {cout<<"请输入被查找者姓名"<<endl;
            string findName;
            cin>>findName;
            Tree::find(ancester,findName);
        break;}
    if(num=5){
        break;
    }}

}
return 0;
}

