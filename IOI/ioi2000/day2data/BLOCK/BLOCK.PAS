program Block;
  {HGF 2000-5-20}
  const
    NameIn1='types.in'; {lib file name}
    NameIn2='block.in'; {input file name}
    NameOut='block.out';{output file name}
    BlockNo=12;         {total building block number}
    BlockLg=4;          {max buiding block size}
    Max=7;              {maxcoordinate of 3D-solid}
    Dep=50;             {maxsize of 3D-solid}
  type
    TXYZ=array[1..4,1..3]of ShortInt; {the coordiante of a building block}
    Rec=record                        {the record to store a building block}
          ID:Integer;                           {ID name}
          No:Byte;                              {size}
          XYZ:TXYZ;                             {original coordinate}  
          Kind:Byte;                            {the kinds that this block can be rotated}
          KindXYZ:array[1..24]of TXYZ           {each kind's coordinates}
        end;
    TAns=array[0..Dep]of Integer;     {type for the answer}
  var
    Lib:array[0..BlockNo]of Rec;      {total building block}
    Big:array[1-BlockLg..Max+BlockLg, {the 3D-solid image}
              1-BlockLg..Max+BlockLg,
              1-BlockLg..Max+BlockLg]of Boolean;
    BigBlock,                         {size of 3D-solid}
    ML:Integer;
    Best:Integer;                     {used block number of best answer}
    Now:TAns;                         {now answer}
    Ans:TAns;                         {best answer}
  procedure DataIn1;  {reading the lib file to form the blocks' data}
    var
      k,i,j,v:Integer;
      Temp:TXYZ;
    procedure CircleA; {rotation with X}
      var
        i:Integer;
        TT:TXYZ;
      begin
        TT:=Temp;
        for i:=1 to v do
          begin
            Temp[i,1]:=TT[i,1];
            Temp[i,2]:=TT[i,3];
            Temp[i,3]:=-TT[i,2]
          end
      end;{of CircleA}
    procedure CircleB; {rotation with Z}
      var
        i:Integer;
        TT:TXYZ;
      begin
        TT:=Temp;
        for i:=1 to v do
          begin
            Temp[i,1]:=-TT[i,2];
            Temp[i,2]:=TT[i,1];
            Temp[i,3]:=TT[i,3]
          end
      end;{of CircleB}
    procedure AddToKind; {check new rotation as a new kind of this building block and add to the list}
      var
        i,j,kk,Sx,Sy,Sz:Integer;
      begin
        Sx:=MaxInt;
        Sy:=MaxInt;
        Sz:=MaxInt;
        for i:=1 to v do
          if (Temp[i,1]<Sx) or
             (Temp[i,1]=Sx) and (Temp[i,2]<Sy) or
             (Temp[i,1]=Sx) and (Temp[i,2]=Sy) and (Temp[i,3]<Sz) then
            begin
              Sx:=Temp[i,1];
              Sy:=Temp[i,2];
              Sz:=Temp[i,3]
            end;
        for i:=1 to v do
          begin
            Dec(Temp[i,1],Sx);
            Dec(Temp[i,2],Sy);
            Dec(Temp[i,3],Sz)
          end;
        for i:=1 to v do
          for j:=i+1 to v do
            if (Temp[j,1]<Temp[i,1]) or
               (Temp[j,1]=Temp[i,1]) and (Temp[j,2]<Temp[i,2]) or
               (Temp[j,1]=Temp[i,1]) and (Temp[j,2]=Temp[i,2]) and (Temp[j,3]<Temp[i,3]) then
             begin
               Sx:=Temp[i,1];
               Sy:=Temp[i,2];
               Sz:=Temp[i,3];
               Temp[i]:=Temp[j];
               Temp[j,1]:=Sx;
               Temp[j,2]:=Sy;
               Temp[j,3]:=Sz
             end;

        for kk:=1 to Lib[k].Kind do
          begin
            i:=1;
            while (i<=v) and
                  (Temp[i,1]=Lib[k].KindXYZ[kk,i,1]) and
                  (Temp[i,2]=Lib[k].KindXYZ[kk,i,2]) and
                  (Temp[i,3]=Lib[k].KindXYZ[kk,i,3]) do Inc(i);
            if i>v then Exit
          end;
        Inc(Lib[k].Kind);
        Lib[k].KindXYZ[Lib[k].Kind]:=Temp
      end;{of AddToKind}
    begin {of DataIn1}
      Assign(Input,NameIn1);
      Reset(Input);
      ML:=0;
      for k:=1 to BlockNo do
        with Lib[k] do
          begin
            ReadLn(ID);
            ReadLn(v);
            if v>ML then ML:=v;
            No:=v;
            for i:=1 to No do
              ReadLn(XYZ[i,1],XYZ[i,2],XYZ[i,3]); {read this block data}
            Temp:=XYZ;                            {check the 24 rotations}
            AddToKind;
            for i:=1 to 3 do
              begin
                CircleA;
                AddToKind;
              end;
           CircleB;
           CircleA;
           AddToKind;
           CircleA;
           CircleA;
           AddToKind;
           for j:=1 to Kind do
             begin
               Temp:=KindXYZ[j];
               for i:=1 to 3 do
                 begin
                   CircleB;
                   AddToKind;
                 end
             end
          end;
      Close(Input)
    end;{of DataIn1}
  procedure SortLib;{sort the block for search}
    var
      i,j:Integer;
    begin
      for i:=1 to BlockNo do
        for j:=i+1 to BlockNo do
          if Lib[j].No>Lib[i].No then
            begin
              Lib[0]:=Lib[i];
              Lib[i]:=Lib[j];
              Lib[j]:=Lib[0]
            end
    end;{of SortLib}

  procedure DataIn2;{read the input file}
    var
      i,x,y,z:Integer;
    begin
      Assign(Input,NameIn2);
      Reset(Input);
      FillChar(Big,SizeOf(Big),False);
      ReadLn(BigBlock);
      for i:=1 to BigBlock do
        begin
          ReadLn(x,y,z);
          Big[x,y,z]:=True
        end;
      Close(Input)
    end;{of DataIn2}

  procedure Doing(t,Bl:Integer); {depth-search}
    var
      x,y,z:Integer;
      i,j,k:Byte;
    begin
      if (t-1)+(Bl+ML-1) div ML>=Best then Exit;       {now used blocks+expected blocks}
      if Bl=0           {now left 3D-solid size}
      then begin        {find a better answer}
              Best:=t-1;
              for i:=1 to t-1 do
                Ans[i]:=Lib[Now[i]].ID 
           end
      else for x:=1 to Max do 
             for y:=1 to Max do
               for z:=1 to Max do
                 if Big[x,y,z] then {find the first uncovered 3D-cube}
                   begin
                     for i:=1 to BlockNo do {search: use i-block's j-rotation to cover the 3D-solid}
                       with Lib[i] do
                         for j:=1 to Kind do
                            if (No<=Bl) then
                              begin
                                k:=1;
                                while (k<=No) and Big[x+KindXYZ[j,k,1],y+KindXYZ[j,k,2],z+KindXYZ[j,k,3]] do Inc(k);
                                if k<=No then Continue;

                                for k:=1 to No do
                                  Big[x+KindXYZ[j,k,1],y+KindXYZ[j,k,2],z+KindXYZ[j,k,3]]:=False;
                                Now[t]:=i;
                                Doing(t+1,Bl-No); {searching next one}
                                for k:=1 to No do
                                  Big[x+KindXYZ[j,k,1],y+KindXYZ[j,k,2],z+KindXYZ[j,k,3]]:=True
                              end;
                     Exit
                   end
    end;{of Doing}
  procedure DataOut;
    var
      i,j,k:Integer;
    begin
      Assign(Output,NameOut);
      Rewrite(Output);
      WriteLn(Best);
      for i:=1 to Best do {sort the answer block ID}
        for j:=i+1 to Best do
          if Ans[j]<Ans[i] then
            begin
              Ans[0]:=Ans[i];
              Ans[i]:=Ans[j];
              Ans[j]:=Ans[0]
            end;
      for j:=1 to Best-1 do
        Write(Ans[j],' ');
      WriteLn(Ans[Best]);
      Close(Output)
    end;{of DataOut}
  begin {of main}
    DataIn1;
    SortLib;
    DataIn2;
    Best:=Dep+1;
    Doing(1,BigBlock); {searching}
    DataOut
  end. {of main}