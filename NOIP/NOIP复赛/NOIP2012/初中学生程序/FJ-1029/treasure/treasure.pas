program treasure;
  var
    map:array[1..10000,0..100]of longint;
    yes:array[1..10000,0..100]of longint;
    num:array[1..10000] of longint;
    n,m,i,j,x,ans:longint;


  procedure find;
    var
      t,j:longint;
    begin
      t:=map[i,x];
      ans:=(ans+t) mod 20123;
      t:=t mod num[i];
      if t=0
        then
          begin
            x:=x+m;
            for j:=1 to m-1 do
              if yes[i,(x-j) mod m]=1
                then
                  begin
                    x:=(x-j) mod m;
                    exit;
                  end;
          end
        else
          begin
            for j:=0 to m-1 do
              begin
                if yes[i,(x+j) mod m]=1
                  then dec(t);
                if t=0
                  then
                    begin
                      x:=(x+j) mod m;
                      exit;
                    end;
              end;
          end;
    end;


begin
  assign(input,'treasure.in');
  reset(input);
  assign(output,'treasure.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=0 to m-1 do
        begin
          readln(yes[i,j],map[i,j]);
          if yes[i,j]=1
            then inc(num[i]);
        end;
    end;
  readln(x);
  for i:=1 to n do
    begin
      find;
    end;
  writeln(ans);
  close(input);
  close(output);
end.
