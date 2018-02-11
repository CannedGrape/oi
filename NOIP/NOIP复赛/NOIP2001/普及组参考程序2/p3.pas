{$r-,q-,s-,n+,g+}
const
	maxn = 205;
	maxk = 41;
var
	p,n,k,caseno:integer;
	s,tmps:string[maxn];
	mlen:array[1..maxn] of integer;
	word:array[1..6] of string;
	g:array[0..maxn,0..maxn] of integer;
	h:array[0..maxn,0..maxk] of integer;
	i,j,u,v:Integer;

	begin
		assign(input,'input3.dat');
		reset(input);
		
		readln(caseno);
		while(caseno>0) do
		begin
			dec(caseno);
			
			{ init; }
			readln(p,k);
			n:=p*20;
			s:='';
			for i:=1 to p do
			begin
				readln(tmps);
				s:=s+tmps;
			end;
			readln(p);
			for i:=1 to p do
				readln(word[i]);
			
			{ precalc mlen }
			for i:=1 to n do
			begin
				mlen[i]:=maxn;
				for j:=1 to p do
					if( (pos(word[j],copy(s,i,length(s)-i+1))=1) and (length(word[j])<mlen[i]) ) then
						mlen[i]:=length(word[j]);
			end;
				
			{ precalc g }
			for i:=1 to n do
				for j:=1 to n do
				begin
					g[i][j]:=0;
					for u:=i to j do
						if(u+mlen[u]-1<=j) then
							inc(g[i][j]);
				end;
			
			{ Dynamic Programming }
			fillchar(h,sizeof(h),0);
			for j:=1 to k do
				for u:=j to n do
					for v:=u to n do
						if(h[u-1][j-1]+g[u][v]>h[v][j])then
							h[v][j]:=h[u-1][j-1]+g[u][v];
			writeln(h[n][k]);
		end;
		
		close(input);
	
	end.