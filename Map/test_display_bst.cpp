#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

//==================

class Tree
{
private:
   struct Node
   {
      int data;
      Node* left  = nullptr;
      Node* right = nullptr;

      Node( int val ) : data( val ) {}
   };

   Node* root = nullptr;
   Node* insert( Node*, int );
   void  print ( Node* );

public:
   void insert( int val ) { root = insert( root, val ); }
   void print() { print( root ); cout << '\n'; }

   // For drawing
private:
   int height( Node* );
   void drawNode( vector<string> &output, vector<string> &linkAbove, Node* node, int level, int minPos, char linkChar );
public:
   void draw();
};

//------------------

Tree::Node* Tree::insert( Node* node, int val )
{
   if ( !node ) return new Node( val );
   if ( val < node->data ) node->left  = insert( node->left, val );
   else                    node->right = insert( node->right, val );   // ...
// if ( val > node->data ) node->right = insert( node->right, val );   // alternative with no repeats
   return node;
}

//------------------

void Tree::print( Node* node )
{
   if ( !node ) return;
   print( node->left  );
   cout << node->data << " ";
   print( node->right );
}

//==================

int Tree::height( Node* node )
{
   if ( !node ) return 0;
   return 1 + max( height( node->left ), height( node->right ) );
}

//------------------

void Tree::drawNode( vector<string> &output, vector<string> &linkAbove, Node* node, int level, int p, char linkChar )
{
   if ( !node ) return;

   int h = output.size();
   string SP = " ";

   if ( p < 0 )       // Shunt everything non-blank across
   {
      string extra( -p, ' ' );
      for ( string &s : output    ) if ( !s.empty() ) s = extra + s;
      for ( string &s : linkAbove ) if ( !s.empty() ) s = extra + s;
   }
   if ( level < h - 1 ) p = max( p, (int)output[level+1].size() );
   if ( level > 0     ) p = max( p, (int)output[level-1].size() );
   p = max( p, (int)output[level].size() );

   // Fill in to left
   if ( node->left )
   {
      string leftData = SP + to_string( node->left->data ) + SP;
      drawNode( output, linkAbove, node->left, level + 1, p - leftData.size(), 'L' );
      p = max( p, (int)output[level+1].size() );
   }

   // Enter this data
   int space = p - output[level].size();  if ( space > 0 ) output[level] += string( space, ' ' );
   string nodeData = SP + to_string( node->data ) + SP;
   output[level] += nodeData;

   // Add vertical link above
   space = p + SP.size() - linkAbove[level].size();   if ( space > 0 ) linkAbove[level] += string( space, ' ' );
   linkAbove[level] += linkChar;

   // Fill in to right
   if ( node->right ) drawNode( output, linkAbove, node->right, level + 1, output[level].size(), 'R' );
}

//------------------

void Tree::draw()
{
   int h = height( root );
   vector<string> output( h ), linkAbove( h );
   drawNode( output, linkAbove, root, 0, 5, ' ' );

   // Create link lines
   for ( int i = 1; i < h; i++ )
   {
      for ( int j = 0; j < linkAbove[i].size(); j++ )
      {
         if ( linkAbove[i][j] != ' ' )
         {
            int size = output[i-1].size();
            if ( size < j + 1 ) output[i-1] += string( j + 1 - size, ' ' );
            int jj = j;
            if ( linkAbove[i][j] == 'L' )
            {
               while ( output[i-1][jj] == ' ' ) jj++;
               for ( int k = j + 1; k < jj - 1; k++ ) output[i-1][k] = '_';
            }
            else if ( linkAbove[i][j] == 'R' )
            {
               while ( output[i-1][jj] == ' ' ) jj--;
               for ( int k = j - 1; k > jj + 1; k-- ) output[i-1][k] = '_';
            }
            linkAbove[i][j] = '|';
         }
      }
   }

   // Output
   for ( int i = 0; i < h; i++ )
   {
      if ( i ) cout << linkAbove[i] << '\n';
      cout << output[i] << '\n';
   }
}

//==================

int main()
{
   srand( time( 0 ) );
// vector<int> A = { 5, 4, 6, 2, 9, 0, 3, 7, 10, 1, 13 };                        // Test input
   vector<int> A;   for ( int i = 0; i < 50; i++ ) A.push_back( rand() % 100 );  // Bigger tree

   Tree tree;
   for ( int i : A ) tree.insert( i );
// tree.print();
   tree.draw();
}