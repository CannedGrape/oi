#include <cstdio>

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N, M, Q;
int map[33][33];
short mark[33][33][33][33];
short mark_value = 0;
const int cannot_reach = 100000000;
int answer = cannot_reach;
int ex, ey, sx, sy, tx, ty;
int que_left, que_right;

struct statef
{
    int x, y, bx, by, step;
	statef(int s, int X, int Y, int BX, int BY)
	    : step(s), x(X), y(Y), bx(BX), by(BY) {}
	statef(){}	   
};

const int queue_size = 900000;
statef que[queue_size];

int intabs(int v)
{
 	return v < 0 ? -v : v;
}

void search()
{
    while(que_left != que_right)
    {
	    statef st = que[que_left++];
	    if(que_left == queue_size) que_left = 0;
	    
	    mark[st.x][st.y][st.bx][st.by] = mark_value;    
	    for(int i = 0; i != 4; ++i)
	    {
		    int nx = st.x + dir[i][0];
			int ny = st.y + dir[i][1];
			if(nx <= 0 || ny <= 0 || nx > N || ny > M)
			    continue;
			if(map[nx][ny] == 0) continue;
			statef next;
			if(nx == st.bx && ny == st.by)
			    next = statef(st.step + 1, nx, ny, st.x, st.y);
			else next = statef(st.step + 1, nx, ny, st.bx, st.by); 	
			
		    int mdis = intabs(next.bx - tx) + intabs(next.by - ty);
		    if(mdis == 0)
			{
		        answer = next.step;
			    return; 	  
		    } else if(mark[next.x][next.y][next.bx][next.by]
				   == mark_value) continue;
			que[que_right++] = next;	
			if(que_right == queue_size) que_right = 0;
			if(que_right == que_left) return;
		}
    }
}

int main()
{
    FILE* input, *output;
    input = std::fopen("puzzle.in", "r");
    output = std::fopen("puzzle.out", "w");
    
    std::fscanf(input, "%d %d %d", &N, &M, &Q);
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            std::fscanf(input, "%d", &map[i][j]);
    
    while(Q--)
    {
        std::fscanf(input, "%d %d %d %d %d %d", 
            &ex, &ey, &sx, &sy, &tx, &ty);
        if(sx == tx && sy == ty)
        {
 	        std::fprintf(output, "0\n");
 	        continue;
 	    }
  		answer = cannot_reach;
        ++mark_value;
        que_left = que_right = 0;
        que[que_right++] = statef(0, ex, ey, sx, sy);
        search();
        if(answer == cannot_reach)
            std::fprintf(output, "-1\n");
        else std::fprintf(output, "%d\n", answer);
    }
    
    std::fclose(input);
    std::fclose(output);
    return 0;
}
