var
ans,n,i,j,l:longint;
a,b:array[1..100000]of longint;
pd:array[1..100000]of boolean;
c:array[0..100000]of longint;
pd3:boolean;
procedure search (l,r:longint);
var i,j,tt:longint;
    pd2,pd3:boolean;
  begin



  pd2:=true;

  while pd2 do
  begin
  inc(ans);

  for i:=l to r do
    inc(b[i]);
  for i:=1 to n do
  if a[i]=b[i] then
  begin
  pd2:=false;
  break;
  end;
  end;

  tt:=l;
  for i:=1 to n do
   if a[i]=b[i] then
    begin
      if i-1>=tt then search(tt,i-1);
      tt:=i+1;
    end;
  if r>=tt then search(tt,r);

  exit;

  end;

begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);

   ans:=0;
  fillchar(b,sizeof(b),0);

  readln(n); //shuru
  for i:=1 to n do
  read(a[i]);

  pd3:=false;

  j:=0;
  for i:=1 to n do
   if a[i]=0 then
     begin
      inc(j);
      c[j]:=i;
      pd3:=true;
     end;
  if pd3 then
  begin
  l:=1;
  for i:=1 to j do
  begin
    search(l,c[i]-1);
    l:=c[i]+1;
  end;
  search(c[j]+1,n);
  end else search(1,n);

  writeln(ans);

 close(input);
  close(output);


      end.
