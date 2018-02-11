var
  n,m,k,x,i,j:longint;
  ac,t : qword;

function work(k:longint):longint;
  var t:qword;
  begin
    if k=0 then exit(1)
    else
    begin
      t:=work(k shr 1);
      if k and 1=0 then exit(t*t mod n)
      else exit(t*t*10 mod n);
    end;
  end;

begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
  read(n,m,k,x);

  t:=work(k);
  ac:=(x+t*m) mod n;

  write(ac);
  close(input); close(output);
end.