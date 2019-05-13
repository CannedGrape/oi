var a:array[1..10000] of longint;
    i:longint;
begin
  for i:=1 to 10000 do
    fillchar(a,sizeof(a),0);
end.
