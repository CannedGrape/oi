program t1999_4;
const maxn=40;
type arr=array[0..maxn]of integer;
var  n,k,i,sum,c:integer;
     a,max,result:arr;

function count(a:arr;k:integer):integer;
var max,sum,i:integer;
    b,c:arr; result:array[0..10000] of integer;
    pp:integer;
begin
    max:=0;
    b[1]:=-1;
    fillchar(result,sizeof(result),0);
    i:=1;sum:=0;c[0]:=0;
    while i>0 do begin
          if i>k then begin
                 i:=i-1;
                 sum:=sum-a[i]*b[i];
            end
          else begin
               b[i]:=b[i]+1;
                c[i]:=c[i-1]+b[i];
                if c[i]<=n then begin
                      sum:=sum+b[i]*a[i];
                      if (sum<10000) and (sum>=0) then
                          result[sum]:=1;
                      i:=i+1;
                      b[i]:=-1;
                  end
                else begin
                      i:=i-1;
                      sum:=sum-a[i]*b[i];
                  end;
            end;
      end;
      i:=1;
      while result[i]=1 do i:=i+1;
      count:=i-1;
end;

begin
    assign(output,'stamp.out');
    rewrite(output);
    assign(input,'stamp.in');
    reset(input);
    readln(n,k);
    sum:=n;c:=1;
    a[1]:=1;max[1]:=n;
    i:=2;a[2]:=a[1];
    while i>1 do begin
        if i>k then begin
               i:=i-1;
           end
        else begin
               a[i]:=a[i]+1;
               if a[i]<=max[i-1]+1 then begin
                     max[i]:=count(a,i);
                     if sum<max[i] then begin
                           sum:=max[i];
                           result:=a;
                           c:=i;
                       end;
                     i:=i+1;
                     a[i]:=a[i-1];
                 end
               else begin
                     i:=i-1;
                 end;
           end;
    end;
    if k=1 then writeln(1)
     else begin
        write(result[1]);
        for i:=2 to c do write(' ',result[i]);
        writeln;
      end;
    writeln('MAX=',sum);
    close(input);
    close(output);
end.
