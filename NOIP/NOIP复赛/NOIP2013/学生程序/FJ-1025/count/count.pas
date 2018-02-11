program count;
var n,a,i,ans:longint;
procedure find(k:longint);
var t:boolean;
begin
  t:=false;
  if k div 1000000>0 then
  begin t:=true; if k div 1000000=a then
  begin ans:=ans+1;  t:=true; end;k:=k mod 1000000;end;
  if (k div 100000>0) or t then
  begin t:=true; if k div 100000=a then
  begin ans:=ans+1; t:=true end;k:=k mod 100000; end;
  if (k div 10000>0)or t then
  begin t:=true;if k div 10000=a then
  begin ans:=ans+1; t:=true;end;k:=k mod 10000;end;
  if (k div 1000>0) or t then
  begin t:=true;if k div 1000=a then
  begin ans:=ans+1;t:=true; end; k:=k mod 1000;end;
  if (k div 100>0) or t then
  begin t:=true; if k div 100=a then
  begin ans:=ans+1;t:=true; end;k:=k mod 100;end;
  if (k div 10>0) or t then
  begin  t:=true;if k div 10=a then
  begin ans:=ans+1; end;k:=k mod 10;end;
  if (k=a) then begin ans:=ans+1; end;

end;


begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  read(n,a);
  ans:=0;
  for i:=1 to n do
  find(i);
  write(ans);
  close(input);
  close(output);
end.
