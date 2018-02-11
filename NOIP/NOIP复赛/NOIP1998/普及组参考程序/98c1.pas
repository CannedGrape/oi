var
  i:integer;
  s,ss:string;
  c:char;
begin
  for i:=123 to 321 do
  begin
    str(i,ss);
    str(i*2,s); ss:=ss+s;
    str(i*3,s); ss:=ss+s;
    for c:='1' to '9' do
      if pos(c,ss)=0 then break;
    if pos(c,ss)=0 then continue;
    writeln(i,' ',i*2,' ',i*3);
  end;
end.
