scriptId = ''
minMyoConnectVersion ='0.2.0'
scriptDetailsUrl = 'https://github.com/James120393/comp140-api-hacking/edit/master/Program/Mouse.lua'
scriptTitle = 'MYO Controller'

    LOCK_THRESHOLD = 800  
    timeSinceLastPose = 0

    description = [[  
    Mouse Control Script

    Control the mouse with your Myo armband!
    Plus move forward and back in a game.
    
    This code was inspired but Thalmic labs Developer Blog URL::http://developerblog.myo.com/myocraft-mouse-control/

    ]]
    controls = [[  
    Controls:  
     - Move arm to control mouse
     - Fist to left click
     - Fingers spread to right click
     - Wave in to Move Forward
     - Wave out to Move Back
     - Double tap to enable or disable cursor control
     ]]


    function notifyUser(edge)  
        if (edge == "down") then
            myo.notifyUserAction()
        end
    end

    function leftClick(edge)  
        notifyUser(edge)
        myo.mouse("left",edge)
    end

    function rightClick(edge)  
        notifyUser(edge)
        myo.mouse("right",edge)
    end

    function forward(edge)  
        notifyUser(edge)
        myo.keyboard("w",edge)
    end

    function back(edge)  
        notifyUser(edge)
        myo.keyboard("s",edge)
    end

    function lockMyo(edge)  
        if (myo.getTimeMilliseconds() - timeSinceLastPose > LOCK_THRESHOLD) then
            myo.controlMouse(false)
            myo.lock()
        end
    end

     STANDARD_BINDINGS = {
        fist            = leftClick,
        fingersSpread   = rightClick,
        waveOut         = forward,
        wavein          = back,
        doubleTap       = lockMyo
    }
    --STANDARD_BINDINGS = true

    bindings = STANDARD_BINDINGS

    function onForegroundWindowChange(app, title)  

        return true


    end

    function activeAppName()  
        return scriptTitle
    end

    function onUnlock()  
        myo.unlock("hold")
        myo.controlMouse(true)
    end

    function onPoseEdge(pose, edge)  
        --pose = conditionallySwapWave(pose)
        --myo.debug("onPoseEdge: " .. pose .. ": " .. edge)
        fn = bindings[pose]
        if fn then
            keyEdge = edge == "off" and "up" or "down"
            fn(keyEdge)
        end

        if (pose ~= "rest" and edge == "off") then
            timeSinceLastPose = myo.getTimeMilliseconds()
        end
    end
