program fruit(input,output);{O(nlogn) sort time,O(n) caculate time}
const maxn=20000;
var i,k,n:integer;
    sum,temp,temp1:longint;
    a:array[1..maxn] of longint;
    ha,hb,tb:integer;

procedure adjust(i,n:integer);
var temp:longint;j:integer;
begin
    while i<=n div 2 do begin
        j:=i+i;
        if j<n then if a[j]>a[j+1] then j:=j+1;
        if a[i]<a[j] then break
          else begin temp:=a[i];a[i]:=a[j];a[j]:=temp;i:=j;end;
    end;
end;

procedure heap_sort(n:integer);
var temp:longint;i:integer;
begin
    for i:=n div 2 downto 1 do adjust(i,n);
    for i:=n-1 downto 1 do begin
        temp:=a[i+1];a[i+1]:=a[1];a[1]:=temp;
        adjust(1,i);
    end;
end;

begin
    assign(input,'fruit.in');
    reset(input);
    readln(n);
    for i:=1 to n do read(a[i]);
    close(input);
    heap_sort(n);

    sum:=0;temp:=0;k:=0;
    ha:=n;hb:=n;tb:=n+1;
    while (ha>=1) or (hb>=tb) do begin
        k:=k+1;
        if ha<1 then begin
             temp1:=a[hb];
             hb:=hb-1;
          end
        else if hb<tb then begin
             temp1:=a[ha];
             ha:=ha-1;
          end
        else if a[ha]<a[hb] then begin
             temp1:=a[ha];
             ha:=ha-1;
          end
        else begin
             temp1:=a[hb];
             hb:=hb-1;
          end;
        temp:=temp+temp1;
        if k mod 2=0 then begin
           sum:=sum+temp;
           tb:=tb-1;a[tb]:=temp;
           temp:=0;
          end;

    end;
    assign(output,'fruit.out');
    rewrite(output);
    writeln(sum);
    close(output);
end.
