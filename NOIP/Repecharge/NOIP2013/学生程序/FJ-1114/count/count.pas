var
  n,a,k,ans:int64;
  i,j:longint;
begin
  assign(input,'count.in');  reset(input);
  assign(output,'count.out');  rewrite(output);
  readln(n,a);
  for i:=1 to n do begin
    k:=i;
    for j:=1 to 6 do begin
      if k mod 10=a then ans:=ans+1;
      k:=k div 10;
      if k=0 then break;
      end;
    end;
  writeln(ans);
  close(input);close(output);
end.
