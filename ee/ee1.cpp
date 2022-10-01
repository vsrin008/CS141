#include <iostream>
using namespace std;
 
int main ()
{
  int n;
  int m;
  int p1;
  int p2;
  int m1;
  int p3;
  int p4;
  int m2;
  string winner;
  int roundEnd;
  bool gameOver = false;
 
 
 
  cin >> n >> m;
  int n1 = n;
  int n2 = n;
 
 
  for (int i = 0; i < m; ++i)
    {
      cin >> p1 >> p2 >> p3 >> p4;
      m1 = p1 * p2;
      m2 = p3 * p4;
      n1 -= m2;
      n2 -= m1;
 
      if ((gameOver == false) && (n1 <= 0) && (n2 <= 0))
	{
	  roundEnd = i + 1;
	  winner = "tie";
	  gameOver = true;
	  //cout << "It's a tie at round " << i+1 << "!";
	  // break;
	}
 
      else if ((gameOver == false) && (n1 <= 0) && (n2 > 0))
	{
	  roundEnd = i + 1;
	  winner = "team2";
	  gameOver = true;
	  // cout << "Team 2 wins at round " << i+1 << "!";
	  // break;
	}
      else if ((gameOver == false) && (n2 <= 0) && (n1 > 0))
	{
	  roundEnd = i + 1;
	  winner = "team1";
	  gameOver = true;
	  // cout << "Team 1 wins at round " << i+1 << "!";
	  // break;
	}
 
      else if ((gameOver == false) && (i >= m - 1) && (n1 > 0) && (n2 > 0))
	{
	  roundEnd = i + 1;
	  winner = "none";
	  gameOver = true;
	  // cout << "Oh no!";
	  // break;
	}
 
    }
 
 
 
  if (winner == "team1")
    {
      cout << "Team 1 wins at round " << roundEnd << "!";
    }
 
  if (winner == "team2")
    {
      cout << "Team 2 wins at round " << roundEnd << "!";
    }
 
  if (winner == "tie")
    {
      cout << "It's a tie at round " << roundEnd << "!";
    }
 
  if (winner == "none")
    {
      cout << "Oh no!";
    }
 
 
  return 0;
}