    void llenar(int ar[][n],int tam){
        for(int f=0;f<tam;f++){
            for(int c=0;c<tam;c++){
                ar[f][c]=-100+rand()%300;
            }
        }
    }

    void printx(int ar[][n],int tam){
        for(int f=0;f<tam;f++){
            for(int c=0;c<tam;c++){
                cout<<"["<<ar[f][c]<<"]\t";
            }
            cout<<endl;
        }
    }