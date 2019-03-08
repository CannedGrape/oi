type
  sol = record
    x, y, z: int64;
  end;

function gcd(a, b: int64): sol;
var
  ans, temp: sol;
begin
  if b=0 then begin
    ans.x:=1;
    ans.y:=0;
    ans.z:=a;
  end else begin
    temp:=gcd(b, a mod b);
    ans.x:=temp.y;
    ans.y:=temp.x-a div b*temp.y;
    ans.z:=temp.z;
  end;
  gcd:=ans;
end;

function mymod(i, j: int64): int64;
begin
  while i<0 do inc(i, j);
  mymod:=i mod j;
end;

var
  i, j: int64;

begin
assign(input, 'mod.in');
assign(output, 'mod.out');
reset(input);
rewrite(output);
  readln(i, j);
  writeln(mymod(gcd(i, j).x, j));
close(input);
close(output);
end.
