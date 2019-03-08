type
  ji=record
       hi,wei:longint;
     end;
var
  n,i,j,t:longint;
  a:array[0..100000]of longint;
  max,min:array[-1..100000]of ji;
procedure zhunbei;
  begin
   for i:=1 to 2 do  read(a[i]);
  for i:=3 to n do
    begin
      read(a[i]);
      if (a[i-2]>=a[i-1])and(a[i-1]<=a[i]) then
        if not((a[i-2]=a[i-1])and(a[i-1]=a[i])) then
          begin
            min[0].hi:=min[0].hi+1;
            min[min[0].hi].wei:=i-1;
            min[min[0].hi].hi:=a[i-1];
          end;
      if (a[i-2]<=a[i-1])and(a[i-1]>=a[i]) then
        if not((a[i-2]=a[i-1])and(a[i-1]=a[i])) then
          begin
            max[0].hi:=max[0].hi+1;
            max[max[0].hi].wei:=i-1;
            max[max[0].hi].hi:=a[i-1];
          end;
    end;
  if a[1]>a[2] then
    begin
      max[0].hi:=max[0].hi+1; max[max[0].hi].hi:=a[1];
      max[max[0].hi].wei:=1;
    end
      else
        begin
          min[0].hi:=min[0].hi+1; min[min[0].hi].hi:=a[1];
          min[min[0].hi].wei:=1;
        end;
  if a[n]>a[n-1] then
    begin
      max[0].hi:=max[0].hi+1; max[max[0].hi].hi:=a[n];
      max[max[0].hi].wei:=n;
    end
      else
        begin
          min[0].hi:=min[0].hi+1; min[min[0].hi].hi:=a[n];
          min[min[0].hi].wei:=n;
        end;
  end;

procedure go(l,r,h:longint);
  var  b,x,hi:longint;
       f:boolean;
  begin
    if l<=r then
      if l=r then begin {writeln(t,' ',a[l],' ',h);}t:=t+a[l]-h;{writeln} end
        else
          begin
            b:=-1;   {writeln(l,' ',r,' ',h,' ',t,' ',min[0].hi);
                     for i:=1 to min[0].hi do writeln(min[i].hi,' ',min[i].wei);writeln;}

            for i:=1 to min[0].hi do
              if (min[i].wei>=l)and(min[i].wei<=r)and(min[i].hi<min[b].hi) then b:=i;
            t:=t+min[b].hi-h ; x:=min[b].wei; hi:=min[b].hi;  f:=false;

            {writeln(min[b].hi,' ',min[b].wei);writeln;}

            if x>l then
              begin
                min[b].wei:=x-1;   f:=true;
                min[b].hi:=a[x-1];
              end;
            if x<r then
              if f then
                begin
                  min[0].hi:=min[0].hi+1;  min[min[0].hi].wei:=x+1;
                  min[min[0].hi].hi:=a[x+1];
                end
                else
                  begin
                    min[b].wei:=x+1;
                    min[b].hi:=a[x+1];
                  end;
            go(l,x-1,hi); go(x+1,r,hi);
          end;
  end;

begin
  assign(input,'puzzle.in');
  assign(output,'puzzle.out');
  reset(input); rewrite(output);

  readln(n);  min[0].hi:=0;   max[0].hi:=0; t:=0;  min[-1].hi:=maxlongint;
  zhunbei; {writeln;}
  go(1,n,0);
  {writeln(t); readln(n);}

  writeln(-1);
  close(input); close(output);
end.
