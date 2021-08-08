    #include<iostream>  
    #include<cstdio>  
    #include<cstdlib>  
    using namespace std;  
    
      
    const int N = 4e6 + 7;  
    int preOrder[N], postOrder[N], inOrder[N]; 
      
    void work(int pl, int pr, int pol, int por){  
        if(pl == pr ) return;   // Ҷ�ӽڵ�ֱ�ӷ���
    
        int i, j, k;  
        for(i = pol, j = 0; postOrder[i] != preOrder[pl +1]; ++i, j++);   // �ҵ�ǰ���������ȵ�λ��
        inOrder[i+1] = preOrder[pl];  
        for(k = por; k > i + 1; --k)  
            postOrder[k] = postOrder[k-1];  
        if(k != por)  
            postOrder[k] = 0;  
        
        work(pl+1, pl+1+j, pol, i);   // �ݹ�������
        work(pl+1+j+1, pr, i+2, por);  // �ݹ�������

    }  
      
    int main(){  
        int n;  
        scanf("%d", &n);   
        for(int i = 0; i < n; ++i)  // ǰ�����
            scanf("%d", &preOrder[i]);    
        for(int i = 0; i < n; ++i)  // �������
            scanf("%d", &postOrder[i]);  
        work(0, n-1, 0, n-1);    // �ݹ�������
        for(int i = 0; i < n; ++i){  
            inOrder[i] += postOrder[i];  
            printf("%d ", inOrder[i]);  
        }    
    }  