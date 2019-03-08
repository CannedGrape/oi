var map:array[0..2000,0..2000]of longint;
 bo:array[0..2000,0..2000]of boolean;
 tmp,x,y,z,n,m,i,p,j,k:longint;

 s:array[1..31000]of longint;

 function max(a,b:longint):longint;
 begin
 if a>b then exit(a); exit(b);
  end;
  function min(a,b:longint):longint;
   begin
    if a<b then exit(a); exit(b);
    end;
begin

assign(input,'truck.in');
assign(output,'truck.out');
reset(input);
rewrite(output);
 readln(n,m);
     fillchar(bo,sizeof(bo),false);
 for i:=1 to m do
  begin
   readln(x,y,z);
    begin

     if bo[x,y] then begin if z>map[x,y]
           then begin
                             map[x,y]:=z;
                              map[y,x]:=z;      end;
                               end
      else begin
      bo[x,y]:=true;
      bo[y,x]:=true;
      map[x,y]:=z;
      map[y,x]:=z;
      end;
     end;
   end;
     for k:=1 to n do
    for i:=1 to n do
     for j:=1 to n do

        if (i<>k) and (k<>j) and (i<>j)
        then map[i,j]:=max(map[i,j],min(map[i,k],map[k,j]));

        readln(p);
        tmp:=0;
        for i:=1 to p do
         begin
          inc(tmp);
         readln(x,y);
         if map[x,y]<>0 then begin
         s[tmp]:=map[x,y];   end else  begin s[tmp]:=-1; end;
          end;
         for i:=1 to tmp do
         writeln(s[i]);
        close(input);
        close(output);



  end.

