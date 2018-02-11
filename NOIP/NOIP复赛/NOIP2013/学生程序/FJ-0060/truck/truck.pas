var a,b,l:array[0..10000,0..10000]of longint;
    map:array[0..10000,0..10000]of boolean;
    n,m,q,i,j,head,tail,x,y,z:longint;
    max,min:longint;
    d:array[0..5000000]of longint;
    v:array[0..5000000]of boolean;
begin
  assign(input,'truck.in');
  assign(output,'truck.out');
   reset(input);
   rewrite(output);
  readln(n,m);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(map,sizeof(map),false);
  fillchar(l,sizeof(l),0);
  for i:=1 to m do
   begin
    readln(x,y,z);
    inc(a[x,0]);a[x,a[x,0]]:=z;b[x,a[x,0]]:=y;
    inc(a[y,0]);a[y,a[y,0]]:=z;b[y,a[y,0]]:=x;
   end;
  readln(q);
  for i:=1 to q do
   begin
    readln(x,y);
    if map[x,y]=true then writeln(l[x,y])else
   begin
    if (a[x,0]=0)or(a[y,0]=0)then writeln(-1)
     else
    begin
     fillchar(v,sizeof(v),false);
     head:=0;tail:=1;d[1]:=x;v[x]:=true;min:=maxlongint;max:=0;
      repeat
       inc(head);
       for j:=1 to a[d[head],0]do
          begin
           if not v[b[d[head],j]] then begin
           inc(tail);d[tail]:=b[d[head],j];v[d[tail]]:=true;end;
            if a[d[head],j]<min then min:=a[d[head],j];
            if b[d[head],j]=y then
             begin if min>max then max:=min;min:=maxlongint;end;
          end;
      until head>=tail;
      if max=0 then max:=-1;
     map[x,y]:=true;l[x,y]:=max;
     map[y,x]:=true;l[y,x]:=max;
     writeln(max);
    end;
   end;
  end;
 close(input);
 close(output);
end.
