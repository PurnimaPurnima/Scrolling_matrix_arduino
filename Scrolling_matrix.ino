String voice;
int bitread(int,int);
void image(int *);
int A[]={96,144,144,240,144,144,144};
int B[]={112,144,144,112,144,144,112};
int C[]={224,16,16,16,16,16,224};
int D[]={112,144,144,144,144,144,112};
int E[]={240,16,16,112,16,16,240};
int F[]={240,16,16,112,16,16,16};
int G[]={240,8,8,232,136,136,240};//5
int H[]={144,144,144,240,144,144,144};
int I[]={224,64,64,64,64,64,224};//3
int J[]={248,32,32,32,40,40,16};//5
int K[]={144,144,80,48,80,144,144};
int L[]={16,16,16,16,16,16,240};
int M[]={136,216,168,136,136,136,136};//5
int N[]={128,136,152,168,200,136,8};//5
int O[]={96,144,144,144,144,144,96};
int P[]={112,144,144,112,16,16,16};
int Q[]={112,136,136,168,168,112,128};
int R[]={112,144,144,112,144,144,144};
int S[]={224,16,16,96,128,128,112};
int T[]={248,32,32,32,32,32,32};
int U[]={144,144,144,144,144,144,96};
int V[]={136,136,136,136,136,80,32};//5
int W[]={136,136,136,136,168,216,136};
int X[]={136,136,80,32,80,136,136};//5
int Y[]={136,136,80,32,32,32,32};//5
int Z[]={248,128,64,32,16,8,248};//5

const int rows[]={2,3,4,5,6,7,8,9};
const int cols[]={10,11,12,13,14,15,16};
int i;
int j;
int k,l,m,n=0;

void setup() 
{
  Serial.begin(9600);
  for(i=0;i<8;i++)
  pinMode(rows[i],OUTPUT);
  for(i=0;i<=6;i++)
  pinMode(cols[i],OUTPUT);
  
  for(i=0;i<=6;i++)
  digitalWrite(cols[i],HIGH);
  for(i=0;i<8;i++)
  digitalWrite(rows[i],LOW);
  
  
  
  
}


void loop()
{ 
  
      if(Serial.available())
    {
  
     //  Serial.println(char(Serial.read()));
       int ch=Serial.read();
       Serial.println(ch);
       switch (ch)
        {
            case'A':case 'a' : image(&A[0]); break;
            case'B':case 'b' : image(&B[0]); break;
            case'C':case 'c' : image(&C[0]); break;
            case'D':case 'd' : image(&D[0]); break;
            case'E':case 'e' : image(&E[0]); break;
            case'F':case 'f' : image(&F[0]); break;
            case'G':case 'g' : image(&G[0]); break;
            case'H':case 'h' : image(&H[0]); break;
            case'I':case 'i' : image(&I[0]); break;
            case'J':case 'j' : image(&J[0]); break;
            case'K':case 'k' : image(&K[0]); break;
            case'L':case 'l' : image(&L[0]); break;
            case'M':case 'm' : image(&M[0]); break;
            case'N':case 'n' : image(&N[0]); break;
            case'O':case 'o' : image(&O[0]); break;
            case'P':case 'p' : image(&P[0]); break;
            case'Q':case 'q' : image(&Q[0]); break;
            case'R':case 'r' : image(&R[0]); break;
            case'S':case 's' : image(&S[0]); break;
            case'T':case 't' : image(&T[0]); break;
            case'U':case 'u' : image(&U[0]); break;
            case'V':case 'v' : image(&V[0]); break;
            case'W':case 'w' : image(&W[0]); break;
            case'X':case 'x' : image(&X[0]); break;
            case'Y':case 'y' : image(&Y[0]); break;
            case'Z':case 'z' : image(&Z[0]); break;
        }
    }

 
}
int bitread(int a, int b)
{
  return((a>>b)&1);
}
void image(int *a)
{
  l=-4;
  
  while(l<=8)
  {
    long start=millis();
    while(millis()-start<=250)
  {
    for(i=0;i<7;i++)
    {
      for(j=0;j<8;j++)
      {
        k=bitread(*(a+i),j);
        if(k==1)
        {
          digitalWrite(j+2-l,HIGH);
          digitalWrite(i+10,LOW);
          digitalWrite(j+2-l,LOW);
          digitalWrite(i+10,HIGH);
        }
      }
    }
  }
  l++;
  }
}

