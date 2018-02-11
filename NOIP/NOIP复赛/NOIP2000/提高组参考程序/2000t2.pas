const
  maxn=40;
  ch:array[0..9] of char='0123456789';
  v:array['0'..'9'] of integer=(0,1,2,3,4,5,6,7,8,9);
type
  pbign=^bign;
  bign=string[maxn];
var
  s:string;
  i,j,k,l,n,c,t:integer;
  x,y:integer;
  r:bign;
  d1,d2:array[1..maxn,1..maxn] of pbign;

procedure mul(a,b:bign; var c:bign); {useful procedure}
var
  tmp:array[1..maxn*2] of integer;
  i,j,g,p,k:integer;
begin
  {init tmp}
  while (length(a)>1)and(a[1]='0') do delete(a,1,1);
  while (length(b)>1)and(b[1]='0') do delete(b,1,1);

  p:=length(a)+length(b);
  for i:=1 to p do
    tmp[i]:=0;

  for i:=1 to length(a) do
    for j:=1 to length(b) do {calc like poly!}
    begin
      k:=p-i-j; {how many '0's}
      inc(tmp[p-k]  ,v[a[i]]*v[b[j]] mod 10); {add here!}
      inc(tmp[p-k-1],v[a[i]]*v[b[j]] div 10);
    end;

  {update tmp}
  g:=0;
  c:='';
  for i:=p downto 1 do
  begin
    c:=ch[(tmp[i]+g) mod 10]+c;
    g:=(tmp[i]+g) div 10;
  end;

  while (length(c)>1)and(c[1]='0') do delete(c,1,1);
end;

function bigger(a,b:bign):boolean;
var
  i:integer;
begin
  bigger:=true;
  if length(a)>length(b) then exit;
  bigger:=false;
  if length(a)<length(b) then exit;
  for i:=1 to length(a) do
    if a[i]<b[i] then exit
    else if a[i]>b[i] then
    begin
      bigger:=true;
      exit;
    end;
end;

begin
  readln(n,c);
  readln(s);
  for i:=1 to n do
    for j:=i to n do
    begin
      new(d1[i,j]);
      new(d2[i,j]);
      d2[i,j]^:=copy(s,i,j);
    end;
  for k:=1 to c do
  begin
    for l:=0 to n do
      for i:=1 to n do
      begin
        j:=i+l;
        if j>n then break;
        d1[i,j]^:='0';
        {where to add first '*': t}
        for t:=i to j-k do {if t>j-k, there will be too many '*'s! }
        begin
          mul(copy(s,i,t-i+1),d2[t+1,j]^,r);
          if bigger(r,d1[i,j]^) then
            d1[i,j]^:=r;
        end;
      end;
    for i:=1 to n do
      for j:=1 to n do
        d2[i,j]^:=d1[i,j]^; {we use pointers so don't use d2:=d1}
  end;
  writeln(d1[1,n]^);
end.
