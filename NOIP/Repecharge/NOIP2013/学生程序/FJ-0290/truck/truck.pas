Var n,m,i,j,x,y,z,tot,q:longint;
    vex,next,cost:array[1..100000] of longint;
    first:array[0..10000] of longint;
    a:array[1..10000,1..10000] of longint;
    v:array[1..200000] of longint;
    c,d:array[1..10000] of boolean;
Function min(x,y:longint):longint;
 begin
  if x<y then exit(x);exit(y);
 end;
Procedure spfa(s,k:longint);
 var  head,tail,i,j,x,y,t:longint;
 begin
    fillchar(c,sizeof(c),0); fillchar(v,sizeof(v),0);
    head:=0; tail:=1; v[1]:=s; c[s]:=true; a[k,s]:=maxlongint;
    while head<tail do
     begin
      inc(head); x:=v[head]; i:=first[x];
      while i>0 do
       begin
        y:=vex[i];  t:=min(a[k,x],cost[i]);
        if t>a[k,y] then
         begin
          a[k,y]:=t;
          if not(c[y]) then
           begin
            inc(tail);
            v[tail]:=y;
            c[y]:=true;
           end;
         end;
        i:=next[i];
       end;
      c[x]:=false;
     end;
 end;
Begin
        Assign(Input,'truck.in');Reset(Input);
        Assign(Output,'truck.out');Rewrite(Output);
 readln(n,m);
 for i:=1 to m do
  begin
   readln(x,y,z);
   inc(tot);
   vex[tot]:=y; cost[tot]:=z; next[tot]:=first[x]; first[x]:=tot;
   inc(tot);
   vex[tot]:=x; cost[tot]:=z; next[tot]:=first[y]; first[y]:=tot;
  end;
 fillchar(a,sizeof(a),$ff);
 readln(q);
 for i:=1 to q do
  begin
   readln(x,y);
   if not(d[x]) then begin d[x]:=true; spfa(x,x); end;
   writeln(a[x,y]);
  end;
        Close(Input);Close(Output);
End.
