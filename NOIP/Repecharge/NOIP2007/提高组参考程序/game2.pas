program game;
type bignum=record x,y:int64; end;
var f:array[1..80,1..80] of bignum;
    s0,s1,s2:bignum;
	max:int64;
    ssz,n0,n,m,i,j,k,l,r:longint;
    a:array[1..80] of longint;
function mb(a,b:bignum):boolean;
begin
  if a.y<>b.y then exit(a.y>b.y);
  mb:=a.x>b.x;
end;
procedure print(a:bignum);
var t:int64;
begin
  if a.y=0 then writeln(a.x) else begin
    write(a.y);
	t:=a.x; 
	while t*10<max do begin write('0'); t:=t*10; end;
	writeln(a.x);
  end;
end;
begin
  max:=10000; max:=max*max; max:=max*max;
  assign(input,'game.in'); reset(input);
  assign(output,'game.out'); rewrite(output);
  s0.x:=0; s0.y:=0;
  readln(n0,m);
  for n:=1 to n0 do begin
     for i:=1 to m do read(a[i]);
     fillchar(f,sizeof(f),0);
     for i:=1 to m do f[i][i].x:=a[i] shl 1;
     for k:=1 to m-1 do 
       for l:=1 to m-k do begin r:=l+k;
          s1.x:=f[l+1][r].x+a[l];
		  s1.y:=f[l+1][r].y+s1.x div max;
		  s1.x:=s1.x mod max;
          s2.x:=f[l][r-1].x+a[r];
		  s2.y:=f[l][r-1].y+s2.x div max;
		  s2.x:=s2.x mod max;
          if mb(s1,s2) then f[l][r]:=s1 else f[l][r]:=s2;
		  with f[l][r] do begin
		     x:=x shl 1; 
			 y:=y shl 1;
			 y:=y+x div max;
			 x:=x mod max;
		  end;
       end;
	with s0 do begin
    x:=x+f[1][m].x; 
	y:=y+f[1][m].y;
    y:=y+x div max;
	x:=x mod max;
    end;
  end;
  print(s0);
  close(input); close(output);
end.

