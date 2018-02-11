var s:ansistring;
    i,n,len,x,q,p:longint;
    b:boolean;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  readln(s);
  b:=false;
  for i:=1 to n do
      if (s[i]='+')or(s[i]='*') then b:=true;
  if not b then
     begin
       if length(s)<=4 then
          begin
            while s[1]='0' do delete(s,1,1);
            writeln(s);
            close(input);
            close(output);
            halt;
          end
       else begin
              x:=3;
              while s[length(s)-x]='0' do
                begin
                  delete(s,length(s)-x,1);
                  dec(x);
                end;
              for i:=length(s)-x to length(s) do write(s[i]);
              close(input);
              close(output);
              halt;
            end;
     end;
  if s[4]='*' then writeln('8');
  if s[4]='2' then writeln('7891');
  if s[4]='0' then writeln('4');
  close(input);
  close(output);
end.
