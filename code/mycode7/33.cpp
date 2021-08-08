#define ll long long


#define pb push_back
 const ll mod=1e9+7;
const int maxsz=3e5+7;
const ll mood=1e9+7;

template<typename key,typename val>
class hash_map{
public:
  struct node{key u;val v;int next;};
  vector<node> e;
  int head[maxsz],nume,numk,id[maxsz];
  int geths(pair<ll,ll> &u){
    int x=(1ll*u.first*mood+u.second)%maxsz;
    if(x<0) return x+maxsz;
    return x;
  }
  val& operator[](key u){
    int hs=geths(u);
    for(int i=head[hs];i;i=e[i].next)if(e[i].u==u) return e[i].v;
    if(!head[hs])id[++numk]=hs;
    if(++nume>=e.size())e.resize(nume<<1);
    return e[nume]=(node){u,0,head[hs]},head[hs]=nume,e[nume].v;
  }
  void clear(){
    for(int i=0;i<=numk;i++) head[id[i]]=0;
    numk=nume=0;
  }
};

hash_map<pair<ll, ll>, int >v;