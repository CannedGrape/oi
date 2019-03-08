program prime;
  var
    n,i,ans:longint;


begin
  assign(input,'prime.in');
  assign(output,'prime.out');
  reset(input);
  rewrite(output);
  read(n);
  for i:=2 to trunc(sqrt(n))+1 do
    begin
      if n mod i=0
        then
          begin
            ans:=n div i;
            break;
          end;
    end;
  write(ans);
  close(input);
  close(output);
end.
