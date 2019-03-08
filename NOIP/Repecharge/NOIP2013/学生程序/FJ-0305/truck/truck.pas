var n,m,i,j,k,x,y,z,q,l:longint;a:array[1..10001,1..10001]of longint;
    b,c:array[1..30001]of longint;
    function min(s1,s2:longint):longint;
    begin
     if s1<s2 then min:=s1 else min:=s2;
    end;
begin
assign(input,'truck.in');
reset(input);
assign(output,'truck.out');
rewrite(output);

 readln(n,m);
      for i:=1 to m do
         begin readln(x,y,z);
          a[x,y]:=z;a[y,x]:=z;
          end;
 readln(q);
 for i:=1 to q do readln(b[i],c[i]);

    for i:= 2 to n-1 do
    for j:=i+1 to n do
     begin for k:=1 to i-1 do

       begin  l:=min(a[i,j],a[k,i]);if l>a[k,j] then
            begin  a[k,j]:=l;a[j,k]:=l;end;
       end;

     end;
    for i:=1 to q do
    begin
     if a[b[i],c[i]]=0 then writeln('-1') else writeln(a[b[i],c[i]]);
     end;

     close(input);
     close(output);
  end.
