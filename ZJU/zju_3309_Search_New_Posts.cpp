// ZOJ_3309_Search New Posts

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class CPostStack 
{
public : 
        void init( void ){
                priority.clear();
                while ( ! heap.empty() ) {
                        heap.pop();
                }
                minPriority = maxPriority = 0;
        }
        void newPost( const string & postName ){
                priority[ postName ] = ++maxPriority;
                heap.push( CNode( postName, maxPriority ) );
        }
        void replyPost( const string & postName ){
                priority[ postName ] = ++maxPriority;
                heap.push( CNode( postName, maxPriority ) );
        }
        void tagPost( const string & postName ){
                priority[ postName ] = --minPriority;
                heap.push( CNode( postName, minPriority ) );
        }
        void search( void ){
                while ( ! que.empty() ) {
                        que.pop();
                }
                for ( int i = 0; i < 100; ++i ) {
                        while ( ( ! heap.empty() ) && ( priority[ heap.top().name ] != heap.top().priority ) ) {
                                heap.pop();
                        }
                        if ( heap.empty() ) {
                                break;
                        }
                        if ( heap.top().priority < 0 ) {
                                break;
                        }
                        cout << heap.top().name << endl;
                        que.push( heap.top() );
                        heap.pop();
                }
                cout << "###" << endl;
                while ( ! que.empty() ) {
                        heap.push( que.front() );
                        que.pop();
                }
        }

private : 
        class CCmp;
        class CNode 
        {
        public : 
                CNode( const string & postName, int p ) : name( postName ), priority( p ){
                }
                string  name;
                int     priority;
                friend class CCmp;
        };
        class CCmp 
        {
        public : 
                bool operator()( const CNode & a, const CNode & b ){
                        return a.priority < b.priority;
                }
        };
        map< string, int > priority;
        priority_queue< CNode, vector< CNode >, CCmp >  heap;
        queue< CNode > que;
        int minPriority, maxPriority;
};

string      name, ope;
CPostStack  st;
int n;

int main(){
        while ( cin >> n ) {
                st.init();
                while ( n-- ) {
                        cin >> ope;
                        if ( ope == "new" ) {
                                cin >> name;
                                st.newPost( name );
                        }
                        else if ( ope == "reply" ) {
                                cin >> name;
                                st.replyPost( name );
                        }
                        else if( ope == "tag" ) {
                                cin >> name;
                                st.tagPost( name );
                        }
                        else {
                                st.search();
                        }
                }
                cout << endl;
        }
        return 0;
}
