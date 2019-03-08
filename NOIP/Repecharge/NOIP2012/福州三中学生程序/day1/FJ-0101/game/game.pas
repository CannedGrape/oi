program game;
var a,b,c,st:array[0..1000]of longint;
    i,j,m,n,k,t:longint;
    min,max:int64;
    s:int64;
    flag:array[1..1000]of boolean;

procedure inp;
begin
	assign(input,'game.in');assign(output,'game.out');reset(input);rewrite(output);
end;

procedure outp;
begin
	close(input);close(output);halt;
end;

procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
     i:=l;
     j:=r;
     x:=c[(l+r) div 2];
     repeat
          while c[i]>x do inc(i);
          while x>c[j] do dec(j);
           if not(i>j) then
             begin
                y:=c[i];
                c[i]:=c[j];
                c[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then sort(l,j);
         if i<r then sort(i,r);
end;

procedure init;
begin
     readln(n);
     for i:=0 to n do
         readln(a[i],b[i]);
     s:=a[0];
     for i:=1 to n do s:=s*a[i];
     for i:=1 to n do c[i]:=a[i]*b[i];
     //for i:=1 to n do st[i]:=s div c[i];
     sort(1,n);
     min:=s;
end;

procedure dfs(pos,now,max,num:int64);
begin
     flag[pos]:=true;
     if num=n then if max<min then min:=max;
     for i:=1 to n do if flag[i]=false then begin
         if now*b[pos]/c[i]>max then max:=(now*b[pos])div c[i];
         dfs(i,(now*b[pos]) div c[i],max,num+1);
     end;
     flag[pos]:=false;
end;

begin
     inp;
     init;
     if n<=50 then for i:=1 to n do dfs(i,s div c[i],s div c[i],1);
     if n>50 then writeln(s div c[1]);
     if n<=50 then writeln(min);
     outp;
end.
