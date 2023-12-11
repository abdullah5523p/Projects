#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*Initializes the 2-d vector array with rows representing pegs, and elements in each row representing the sizes of the discs present in each peg in ascending size */
void initialize_arr(vector<vector<int>>& disc_vect, int num_disc, int start_index); 
/*Prints out the move and updates the 2-d vector array representing the pegs and the discs in them */
void move(int from, int to, vector<vector<int>>& disc_vect, int num_disc); 
/*Displays the pegs and discs at each move */
void display(vector<vector<int>> disc_vect, int num_disc); 
/*Solves the base case for the tower's of hanoi recursive algorithm */
void base_case_hanoi(vector<vector<int>>& disc_vect, int num_disc, int disc_total, int start, int final, int &steps);
/*The main recursive algorithm for solving the towers of hanoi */
void hanoi(vector<vector<int>> &disc_vect, int num_disc, int disc_total, int start, int final, int &steps); 
/*Obtains valid input from the user for number of pegs*/
int get_num_pegs();
/*Obtains valid input from the user for number of discs*/
int get_num_discs();
/*Obtains valid input from the user for starting peg*/
int get_starting_point(int num_pegs);
/*Obtains valid input from the user for final peg*/
int get_ending_point(int num_pegs, int starting_point);
/*Checks trivial impossibility case*/
bool impossible(int num_pegs, int num_disc);



int main() 
{   
 /*Initializing  variables and parameters to be used for the towers of hanoi problem
 /*/////////////////////////////////////////////////////////////////////////////////*/ 
 int steps=0;
 int num_disc;
 int starting_point;
 int end_point;
 int num_pegs;
 /*/////////////////////////////////////////////////////////////////////////////////*/
 /*/////////////////////////////////////////////////////////////////////////////////*/


 /*Gathering inputs for solving the general n-disc, k-peg towers of hanoi problem*/
 /*/////////////////////////////////////////////////////////////////////////////////*/
 num_pegs=get_num_pegs();
 num_disc=get_num_discs();
 cout<<"\nFor left most peg, enter 1. \nFor second peg, enter 2. \nFor third peg, enter 3, and so on.....\n";
 starting_point=get_starting_point(num_pegs);
 end_point=get_ending_point(num_pegs, starting_point);
 cout<<"\n";
 /*/////////////////////////////////////////////////////////////////////////////////*/
 /*/////////////////////////////////////////////////////////////////////////////////*/


 /*Checking trivial case of impossibility with only 2 pegs and more than 1 disc*/
 /*/////////////////////////////////////////////////////////////////////////////////*/
 if (impossible(num_pegs, num_disc))
 {
   cout<<"Impossible to solve.\n";
   return 1;
 }
 /*/////////////////////////////////////////////////////////////////////////////////*/
 /*/////////////////////////////////////////////////////////////////////////////////*/


 /*Initializing pegs and disc 2-d vector array and displaying initial position
 /*/////////////////////////////////////////////////////////////////////////////////*/
 vector<vector<int>> disc_vect(num_pegs);
 initialize_arr(disc_vect, num_disc, starting_point-1);
 cout<<"Initial position: \n\n";
 display(disc_vect, num_disc);
 /*/////////////////////////////////////////////////////////////////////////////////*/
 /*/////////////////////////////////////////////////////////////////////////////////*/


 /*Main computing and ouput occurs here
 /*/////////////////////////////////////////////////////////////////////////////////*/
 hanoi(disc_vect, num_disc, num_disc, starting_point, end_point, steps);
 cout<<"It took "<<steps<<" step(s).\n";
 /*/////////////////////////////////////////////////////////////////////////////////*/
 /*/////////////////////////////////////////////////////////////////////////////////*/
 
 return 0;
}


/*Definitions of all functions to be used
/*/////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////*/


/*Definition of get_num_pegs() function
/*/////////////////////////////////////////////////////////////////////////////////*/
int get_num_pegs()
{
  double n1;/*dummy variable to make sure input is not a double*/
  int n2;
  cout<<"\nPlease enter number of pegs to solve Tower of Hanoi for (at least 2): ";
  cin>>n1;
  n2=n1;
  while(cin.fail() || n1!=n2 || n2<=1) /*Makes sure number of pegs is greater than one. Also makes sure input entered is of type int*/
  {
    if (cin.fail())
    {
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout<<"\nInvalid number of pegs. Try again.\n";
    cout<<"Please enter number of pegs to solve Tower of Hanoi for (at least 2): ";
    cin>>n1;
    n2=n1;
  }
  return n2;
}
/*/////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////*/


/*Definition of get_num_discs() function
/*/////////////////////////////////////////////////////////////////////////////////*/
int get_num_discs()
{
  double n1;/*dummy variable to make sure input is not a double*/
  int n2;
  cout<<"\nPlease enter number of discs to solve Tower of Hanoi for: ";
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cin>>n1;
  n2=n1;
  while(cin.fail() || n2<=0 || n1!=n2)/*Makes sure number of discs is greater than zero, and is not any data type other than int*/
  { 
    if (cin.fail())
    {
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout<<"\nInvalid number of discs. Try again.\n";
    cout<<"Please enter number of discs to solve Tower of Hanoi for: ";
    cin>>n1;
    n2=n1;
  }
  return n2;
}
/*/////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////*/


/*Definition of get_starting_point() function
/*/////////////////////////////////////////////////////////////////////////////////*/
int get_starting_point(int num_pegs)
{
 double n1;/*dummy variable to make sure input is not a double*/
 int n2;
 cout<<"\nPlease enter starting peg of discs: ";
 cin.ignore(numeric_limits<streamsize>::max(),'\n');
 cin>>n1;
 n2=n1;
 while(cin.fail() || n2<=0 || n2>num_pegs || n1!=n2)/*Makes sure starting point is in range of number of pegs. Also makes sure input entered is of type int*/
  { 
    if (cin.fail())
    {
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout<<"\nInvalid peg. Try again.\n";
    cout<<"Please enter starting peg of discs: ";
    cin>>n1;
    n2=n1;
  }
  return n2;
}
/*/////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////*/


/*Definition of get_ending_point() function
/*/////////////////////////////////////////////////////////////////////////////////*/
int get_ending_point(int num_pegs, int starting_point)
{
 double n1;/*dummy variable to make sure input is not a double*/
 int n2;
 cout<<"\nPlease enter final destination peg of discs: ";
 cin.ignore(numeric_limits<streamsize>::max(),'\n');
 cin>>n1;
 n2=n1;
 while(cin.fail() || n2!=n1 || n2<=0 || n2>num_pegs || n2==starting_point)/*Makes sure ending point is in range of number of pegs and not the same as the starting peg. Also makes sure input entered is of type int*/
  { 
    if (cin.fail())
    {
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout<<"\nInvalid peg. Try again.\n";
    cout<<"Please enter final destination peg of discs: ";
    cin>>n1;
    n2=n1;
  }
  return n2;
}
/*/////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////*/


/*Definition of impossible() function
/*/////////////////////////////////////////////////////////////////////////////////*/
bool impossible(int num_pegs, int num_disc)
{
 int check=false;
 if (num_pegs==2 && num_disc>1)
 {
   check=true;
 }
  return check;
}
/*/////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////*/


/*Definition of initialize_array() function
/*/////////////////////////////////////////////////////////////////////////////////*/
void initialize_arr(vector<vector<int>>& disc_vect, int num_disc, int start_index)
{
  for (int i=0; i<disc_vect.size(); i++)
  {
    if (i==start_index)
    {
       for (int j1=1; j1<=num_disc; j1++)
       {
         disc_vect[i].push_back(2*j1+1);/*fills the row vector representing the starting peg with discs of ascending sizes of the form 2*i+1 (even numbers)*/
       }
    }
    else
    {
       for (int j2=0; j2<num_disc; j2++)
       {
         disc_vect[i].push_back(0);/*fills all other row vectors representing all other pegs with discs of size 0*/
       }
    }
  }
}
/*/////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////*/


/*Definition of move() function
/*/////////////////////////////////////////////////////////////////////////////////*/
void move(int from, int to, vector<vector<int>>& disc_vect, int num_disc)
{
  int disc;/*dummy variable to hold disc size for exchange*/
  int to_index;/*hold index of place where disc is to be moved to*/
  int from_index;/*hold index of place from where disc is moved from*/
  bool flag1=false;/*booleans to indicate whether target index is found in the following loop*/
  bool flag2=false;
  cout<<"Move disc from peg "<<from<<" to peg "<<to<<":\n\n";
  for(int i=0; i<num_disc; i++)
  { 
     if (disc_vect[from-1][i]!=0 && !flag1)/*finds index of disc to be moved from one peg to the other*/
     { 
       flag1=true;
       from_index=i;
     }
     if (disc_vect[to-1][i]!=0 && !flag2)/*finds index where the peg needs to be placed after removing from the other peg*/
     {
       flag2=true;
       to_index=i-1;
     }
     if (flag1 && flag2)
     {
       break;/*breaks out of loop if both indices are found*/
     }
  } 
  if (!flag2)/*In case the destination peg is empty*/
  {
     to_index=num_disc-1;
  }
  disc=disc_vect[from-1][from_index];/*updating the disc count and sizes of the pegs involved in the movement*/
  disc_vect[from-1][from_index]=0;
  disc_vect[to-1][to_index]=disc; 
}
/*/////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////*/


/*Definition of display() function
/*/////////////////////////////////////////////////////////////////////////////////*/
void display(vector<vector<int>> disc_vect, int num_disc)
{
 string base;/*string to hold visualization of tower base*/
 string spaces;/*string to hold empty spaces to display between different tower levels*/ 
 int num_width=2*(num_disc+1)+1;/*width of the base of a tower*/
 string label_space;/*string to hold spaces between labels to be displayed*/
 for (int b=0; b<num_width; b++)/*initializing strings for representing the base of the pegs and spaces between labels (half the size of the base-1) for aesthetic appeal*/
 {
   base+="-";
   if(b<num_width/2)
   {
     label_space+=" ";
   }
 }
 for (int i=0; i<num_disc; i++)/*prints out visual representation of the tower by printing discs for each peg according to their size through each iteration*/
 {
   for (int j=0; j<disc_vect.size(); j++) 
   { 
     int num_stars=disc_vect[j][i];
     spaces="";
     for(int y1=0; y1<(num_width-num_stars)/2; y1++)
     {
       spaces+=" ";
     }
     for(int y2=(num_width-num_stars)/2; y2<(num_width+num_stars)/2; y2++)
     {
       spaces+="*";
     }
     for(int y3=(num_width+num_stars)/2; y3<num_width; y3++)
     {
       spaces+=" ";
     }
     cout<<spaces<<"   ";
   }
   cout<<"\n";/*moves on to print the next level of discs of each peg*/
 }
 for (int k=0; k<disc_vect.size(); k++)/*prints out the base at the bottom of each peg*/
 {
   cout<<base<<"   ";
 }
 cout<<"\n";
 for (int h=0; h<disc_vect.size(); h++)/*prints out the base at the bottom of each peg*/
 {
   cout<<label_space<<h+1<<label_space<<"   ";
 }
 cout<<"\n\n";/*Leaves lines for next move*/
}
/*/////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////*/


/*Definition of base_case_hanoi() function
/*/////////////////////////////////////////////////////////////////////////////////*/
void base_case_hanoi(vector<vector<int>>& disc_vect, int num_disc, int disc_total, int start, int final, int &steps)
{
  vector<int> dest;/*initializing vector to hold all possible valid destinations except final*/
  for (int j=1; j<=disc_vect.size(); j++)
  {
    if (j!=start && j!=final)/*filling vector array holding all available possible destinations except the final peg*/
    {    
     dest.push_back(j);
    }
  }
  for (int i=0; i<num_disc; i++)/*makes the moves needed to solve the base case*/
  { 
    if (i==num_disc-1)
    {
      move(start, final , disc_vect, disc_total);/*moves the last peg to the final destination peg*/
      display(disc_vect, disc_total);/*display move*/
      steps++;/*increment the number of steps*/
    }
    else
    {
     move(start, dest[i] , disc_vect, disc_total); /*seperates all discs except last one to all available but different pegs*/
     display(disc_vect, disc_total);/*display move*/
     steps++;
    }
  }
  for (int k=num_disc-2; k>=0; k--)
  {
    move(dest[k], final, disc_vect, disc_total);/*moves all seperated pegs back in reverse order onto the final peg*/
    display(disc_vect, disc_total);/*display move*/
    steps++;/*increment the number of steps*/
  }
}
/*/////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////*/


/*Definition of hanoi() function
/*/////////////////////////////////////////////////////////////////////////////////*/
void hanoi(vector<vector<int>> &disc_vect, int num_disc, int disc_total, int start, int final, int &steps)
{  
   if(num_disc<disc_vect.size())/*If existing problem is trivial, that is, the total number of discs is less than the number of pegs*/
   {
     base_case_hanoi(disc_vect, num_disc, disc_total, start, final, steps);
   } 
   else
   { 
     int dest;/*Hold the destination to be found in the following for loop*/
     if(final==disc_vect.size() | start==disc_vect.size())/*Find farthest possible available destination to the right (highest peg number) for movement of first disc, to prevent intersections with any other future moves, as movement begins from the right-most (lowest peg number) available disc*/ 
     {
       if(final==disc_vect.size()-1 | start==disc_vect.size()-1)
       {
         dest=disc_vect.size()-2;
       }
       else
       {
         dest=disc_vect.size()-1;
       }  
     }
     else
     {
       dest=disc_vect.size();
     }

     /*seperate n-discs into k-1 hypothetical discs by combining some of them, where k is the number of pegs.
     We do this because our base case can only deal with at most k-1 discs. Now apply the same algorithm as for k-1 discs*/
     hanoi(disc_vect, num_disc-(disc_vect.size()-2), disc_total, start, dest, steps); /*Moves "top" disc (actually n-k+2 discs) to farthest available peg to prevent any future problems with bigger discs placed onto smaller ones*/
     base_case_hanoi(disc_vect, disc_vect.size()-2, disc_total, start, final, steps);/*Moves the bottom k-2 discs to the final destination*/
     hanoi(disc_vect, num_disc-(disc_vect.size()-2), disc_total, dest, final, steps);/*Moves the "top" disc (actually n-k+2 discs) to the final destination, completing the puzzle*/
   }
}
/*/////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////*/