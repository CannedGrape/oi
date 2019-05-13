(*
第三题：
图论题，两次SPFA，用a[i]表示从起点开始到i结点能经过的最小值，用b[i]表示从终点延反向边到达i结点能经过的最大值。Ans=max(b[i]-a[i])。
*)
const
     maxn=100010;
     maxm=1000010;
type
    data=record
        t,f,next:longint;
    end;
var
   n,m,ls:longint;
   a,c,d,stack,v:array[0..maxn]of longint;
   f:array[1..maxn]of boolean;
   seg:array[1..maxm]of data;

procedure insert_e(s,t,f1,f2:longint);
begin
      inc(ls);
      seg[ls].t:=t;
      seg[ls].f:=f1;
      seg[ls].next:=a[s];
      a[s]:=ls;
      inc(ls);
      seg[ls].t:=s;
      seg[ls].f:=f2;
      seg[ls].next:=a[t];
      a[t]:=ls;
end;
procedure init;
var
   i,j,k,l:longint;
begin
    readln(n,m);
    fillchar(a,sizeof(a),255);
    ls:=0;
    for i:=1 to n do read(v[i]);
    for i:=1 to m do
    begin
         readln(j,k,l);
         if l=1 then insert_e(j,k,1,2)
         else insert_e(j,k,3,3);
    end;
end;
function max(a,b:longint):longint;
begin
   if a>b then exit(a) else exit(b);
end;
function min(a,b:longint):longint;
begin
   if a<b then exit(a) else exit(b);
end;
procedure spfa1;
var
   i,k,open,closed:longint;
begin
     fillchar(c,sizeof(c),127);
     fillchar(f,sizeof(f),0);
     f[1]:=true;
     open:=0;
     closed:=1;
     stack[1]:=1;
     c[1]:=v[1];
     while open<closed do
     begin
          inc(open);
          k:=stack[open mod maxn];
          f[k]:=false;
          i:=a[k];
          while i<>-1 do
          begin
               if (seg[i].f and 1=1)and(min(c[k],v[seg[i].t])<c[seg[i].t]) then
               begin
                     c[seg[i].t]:=min(c[k],v[seg[i].t]);
                     if not f[seg[i].t] then
                     begin
                          f[seg[i].t]:=true;
                          inc(closed);
                          stack[closed mod maxn]:=seg[i].t;
                     end;
               end;
               i:=seg[i].next;
          end;
     end;
end;
procedure spfa2;
var
   i,k,open,closed:longint;
begin
     fillchar(d,sizeof(d),0);
     fillchar(f,sizeof(f),0);
     f[n]:=true;
     open:=0;
     closed:=1;
     stack[1]:=n;
     d[n]:=v[n];
     while open<closed do
     begin
          inc(open);
          k:=stack[open mod maxn];
          f[k]:=false;
          i:=a[k];
          while i<>-1 do
          begin
               if (seg[i].f and 2=2)and(max(d[k],v[seg[i].t])>d[seg[i].t]) then
               begin
                     d[seg[i].t]:=max(d[k],v[seg[i].t]);
                     if not f[seg[i].t] then
                     begin
                          f[seg[i].t]:=true;
                          inc(closed);
                          stack[closed mod maxn]:=seg[i].t;
                     end;
               end;
               i:=seg[i].next;
          end;
     end;
end;
procedure main;
var
i,ans:longint;
begin
    spfa1;
    spfa2;
    ans:=0;
    for i:=1 to n do
      ans:=max(ans,d[i]-c[i]);
    writeln(ans);
end;
begin
     assign(input,'trade.in');
     reset(input);
     assign(output,'trade.out');
     rewrite(output);
     init;
     main;
     close(input);
     close(output);
end.
