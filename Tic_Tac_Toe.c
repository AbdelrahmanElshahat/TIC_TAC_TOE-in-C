#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
/** Global variables **/
int player = 0, computer = 1;
char positions[9] = {'1','2','3','4','5','6','7','8','9'};
int board[9]={0};
int i,j;
void start_game();
void initialize_board();
void play();
void comp_turn();
void update_board();
int predict_result( int board[9]);

int main()
{
    start_game();
    initialize_board();
    while(1){
        play();
        update_board();

    switch((predict_result(board)))
    {
    case 1 :
        printf("player  win.\n");
        printf("\n");
            break;
            case 2 :
            printf("computer win.\n");
            printf("\n");
            break;
        }

        if(predict_result(board)){
                    break;
        }
        int j=0;
        for(i=0;i<9;i++){
            if((board[i] !=0 )){
                j++;
            }
        }
        if (j==9)
            {
                printf("Draw\n");
                break;
            }
    }
    return 0;
}


void start_game()
{                    /** Choose to play X or Y **/
    int turn;
   char move;
   printf("Choose (1) for x and (0) for o :");
   scanf("%d",&turn);
   if(turn){
    player = 1;
    computer = 0;
   }
}
void initialize_board()
{
               /**making board shape **/

    printf(" %c | %c | %c\n",positions[0],positions[1],positions[2]);
    printf("-------------\n");
    printf(" %c | %c | %c\n",positions[3],positions[4],positions[5]);
    printf("-------------\n");
    printf(" %c | %c | %c\n",positions[6],positions[7],positions[8]);
    printf("\n\n");

}
void play()
{                    /**Player turn To choose position to play in**/
    int pos ;
    char move;
    if(player){
        move='x';
    }
    else{
        move='o';
    }
    printf("Enter position You want to play in: ");
    scanf("%d",&pos);
    system("CLS");
if(board[pos-1] == 0 && ( pos>=1 && pos<=9))
        {
            board[pos-1]=1;
    positions[pos-1]=move;
        }
        else {
            printf("position if occupied:\n");
        }
comp_turn();

}
                           /**            DEFENDING STRATGEY    [unbeaten algorthim ]       **/
void comp_turn()
{

    char move;
    if(computer){
        move='x';
    }
    else{
        move='o';
    }
    if(board[4] == 0){
            positions[4] = move;
            board[4] =2;
}
if((board[0] == 1) && (board[2] == 1) && ( board[1] == 0 ))
                {
                  positions[1]=move;
                   board[1]=2;
                }
                   if((board[7]==1) && ( board[5] == 0) ){
                    positions[5]=move;
                    board[5]=2;
                   }
             else if((board[6] == 1) && (board[8] == 1 )&& ( board[7] == 0) )
            {
                positions[7]=move;
                   board[7]=2;
            }
            else if((board[0] == 1) && (board[1] == 1) && ( board[2] == 0))
                {
                    positions[2] = move;
                     board[2] = 2 ;
                } else if((board[0] == 1) && (board[3] == 1) && ( board[6] == 0) )
                {
                    positions[6] = move;
                     board[6] = 2 ;
                } else if((board[0] == 1) && (board[6] == 1) && ( board[3] == 0))
                {
                    positions[3] = move;
                    board[3] = 2;
                    if((board[5] == 1) && (board[7] == 0)){
                            positions[7]=move;
                    board[7]=2;
                    }

                }else if((board[2] == 1) && (board[1] == 1) && ( board[0] == 0 ))
                {
                    positions[0]=move;
                    board[0]=2;
                }else if((board[2] == 1) && (board[5] == 1) && ( board[8] == 0))
                {
                    positions[8]=move;
                    board[8]=2;
                }else if((board[2] == 1) && (board[8] == 1) && ( board[5] == 0))
                {
                    positions[5]=move;
                    board[5]=2;
                }
                else if((board[6] == 1) && (board[3] == 1) && ( board[0] == 0))
                {
                    positions[0]=move;
                    board[0]=2;
                }
                else if((board[6] == 1) && (board[7] == 1) && ( board[8] == 0))
                {
                    positions[8]=move;
                    board[8]=2;
                }else if((board[8] == 1) && (board[7] == 1) && ( board[6] == 0))
                {
                    positions[6]=move;
                    board[6]=2;
                }

                if((board[4] == 1) && (board[0] == 0) && (board[1] == 0) && (board[2] == 0) && (board[3] == 0) && (board[5] == 0) && (board[6] == 0) && (board[7] == 0) && (board[8] == 0) )

                {
                    positions[0] = move;
                    board[0]=2;

                }if ((board[4] == 1) && (board[2] == 1) && (board[6] == 0)){
                    positions[6] = move;
                    board[6] = 2;
                }else if ((board[4] == 1) && (board[6] == 1) && (board[2] == 0))
                {
                positions[2] = move;
                board[2]=2;
                }else if ((board[4] == 1) && (board[0] == 1) && (board[8] == 0) )
                {
                    positions[8] =move;
                    board[8]=2;
                }
                else if ((board[4] == 1) && (board[8] == 1) && (board[0] == 0))
                {
                    positions[0]=move;
                    board[0]=2;
                }
                else if((board[3] == 1) && (board[4] == 1) && (board[5] == 0)){
                    positions[5] = move;
                    board[5]=2;
                }
                else if((board[1] == 1) && (board[4] == 1) && (board[7] ==0) ){
                    positions[7]=move;
                    board[7]=2;
                }else if((board[4] == 1) && (board[7] == 1) && (board[1] ==0)){
                    positions[1] =move;
                    board[1] = 2;
                }else if((board[1] == 1) && (board[7] == 1) && (board[4] ==0)){
                    positions[4] =move;
                    board[4] = 2;
                } else if((board[0] == 2) && (board[8] == 1) && (board[4] == 1)  &&  (board[5] ==0)){
                    board[5]=2;
                    positions[5]=move;
                }else if((board[2] == 2 ) && (board[6] == 1) && (board[4] == 2)  &&  (board[3] ==0)){
                    board[3]=2;
                    positions[3]=move;
                }
                else if((board[1] == 1 ) && (board[1] == 1) && (board[4] == 2)  &&  (board[6] ==0)){
                    positions[6]=move;
                    board[6]=2;
                }else if((board[3] == 1 ) && (board[4] == 2) && (board[5] == 2)  &&  (board[6] ==0)){
                     positions[6]=move;
                    board[6]=2;
                    if(board[2]==0){
                        positions[2] = move;
                        board[2]=2;
                    }else if((board[2] == 1)){
                        positions[0]=move;
                        board[0]=2;
                    }
                }
                else if((board[2] == 1) && (board[3] == 1) && ( board[4] == 2 ))
                {
                  positions[0]=move;
                   board[0]=2;
                }
                 else if((board[1] == 1) && (board[8] == 0) && (board[2] == 1) && (board[3] == 1) && ( board[4] == 2 ) ){
                    board[8]=2;
                    positions[8]=move;
                   }
}
void update_board()
{
    printf(" %c | %c | %c\n",positions[0],positions[1],positions[2]);
    printf("-------------\n");
    printf(" %c | %c | %c\n",positions[3],positions[4],positions[5]);
    printf("-------------\n");
    printf(" %c | %c | %c\n",positions[6],positions[7],positions[8]);

}
int predict_result( int board[9])
{
   /**   check if any player wins  **/
for(i = 0; i < 8; ++i) {
    int wins[8][3] ={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    if(board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}
