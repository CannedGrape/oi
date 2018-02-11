(*
第四题：
搜索题，有时候这个世界需要些暴力。DFS搜索，每次选取填入的数的方案数进行枚举。
PS：据说从右下角直接枚举到左上角，比加剪枝也能拿95分。
*)
var
   n,ans,l,time:longint;
   a:array[1..81,1..3]of longint;
   c:array[1..27,0..9]of boolean;
   v:array[1..81]of longint;
   d,d2,d3:array[1..81]of longint;
   o:array[1..81]of longint;

function max(a,b:longint):longint;
begin
    if a>b then exit(a) else exit(b);
end;
function min(a,b:longint):longint;
begin
    if a<b then exit(a) else exit(b);
end;
procedure init;
var
   i,j,k:longint;
begin
     for i:=1 to 9 do
     for j:=1 to 9 do
     begin
          k:=(i-1)*9+j;
          a[k,1]:=i;
          a[k,2]:=j+9;
          a[k,3]:=(i-1)div 3*3+(j-1)div 3+1+18;
          v[k]:=10-max(abs(i-5),abs(j-5));
     end;
     fillchar(c,sizeof(c),1);
     for i:=1 to 81 do
     begin
        read(d[i]);
        c[a[i,1],d[i]]:=false;
        c[a[i,2],d[i]]:=false;
        c[a[i,3],d[i]]:=false;
     end;
end;
procedure check;
var
   i,t:longint;
begin
     t:=0;
     for i:=1 to 81 do
        inc(t,d[i]*v[i]);
     if t>ans then ans:=t;
end;
procedure dfs(dep:longint);
var
   i,k:longint;
begin
    if dep>l then begin check;exit;end;
{   if dep<1 then begin check;exit;end;}
    inc(time);
    if time>10000000 then begin writeln(ans);close(input);
close(output);halt;end;
    k:=o[dep];
    for i:=1 to 9 do
    if c[a[k,1],i] and c[a[k,2],i] and c[a[k,3],i] then
    begin
         c[a[k,1],i]:=false;
         c[a[k,2],i]:=false;
         c[a[k,3],i]:=false;
         d[k]:=i;
         dfs(dep+1);
         d[k]:=0;
         c[a[k,1],i]:=true;
         c[a[k,2],i]:=true;
         c[a[k,3],i]:=true;
    end;
end;
procedure main;
var
   i,j,k,t:longint;
begin
     d2:=d;
     for i:=1 to 81 do
        d3[i]:=9;
     for i:=1 to 81 do
        if d2[i]>0 then
        begin
             for j:=1 to 81 do
               if (a[i,1]=a[j,1])or(a[i,2]=a[j,2])or(a[i,3]=a[j,3]) then
                 dec(d3[j]);
        end;
     l:=0;
     while true do
     begin
          k:=maxlongint;
          for i:=1 to 81 do
             if (d2[i]=0)and(d3[i]<k) then
             begin
                  k:=d3[i]*11+v[i];
                  j:=i;
             end;
          if k=maxlongint then break;
          inc(l);
          o[l]:=j;
          d2[j]:=10;
          for i:=1 to 81 do
               if (a[i,1]=a[j,1])or(a[i,2]=a[j,2])or(a[i,3]=a[j,3]) then
                 dec(d3[j]);
     end;    
     time:=0;
     ans:=-1;
     dfs(1);
     writeln(ans);

end;
begin
     assign(input,'sudoku.in');
     reset(input);
     assign(output,'sudoku.out');
     rewrite(output);
     init;
     main;
     close(input);
     close(output);
end.
