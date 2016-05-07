scriptId = 'com.james120393.falmouth'
minMyoConnectVersion ='0.3.0'
scriptDetailsUrl = 'https://github.com/James120393/comp140-api-hacking/edit/master/Program/Mouse.lua'
scriptTitle = 'MYO Controller'

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
     - Wave in for F1
     - Wave out for F2
     - Double tap to enable or disable controler
     ]]

	--Sets the locking time after the lock pose is given.
    LOCK_THRESHOLD = 800
    timeSinceLastPose = 0



	--Here the controls are set up for each button.
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

    function builder(edge)
        notifyUser(edge)
        myo.keyboard("f1",edge)
    end

    function army(edge)
        notifyUser(edge)
        myo.keyboard("f2",edge)
    end

	--The locking mechanism is set up.
    function lockMyo(edge)
        if (myo.getTimeMilliseconds() - timeSinceLastPose > LOCK_THRESHOLD) then
            myo.controlMouse(false)
            myo.lock()
        end
    end

	--Binding of the poses to the set-up functions.
	STANDARD_BINDINGS = {
        fist            = leftClick,
        fingersSpread   = rightClick,
        waveOut         = army,
        waveIn          = builder,
        doubleTap       = lockMyo
    }

	--Applies the stated poses to the respective buttons.
    bindings = STANDARD_BINDINGS

	--The application that the Myo will work with is declared
	--As it returns true it will work on any application.
    function onForegroundWindowChange(app, title)
        return true
    end

    function activeAppName()
        return scriptTitle
    end

	--Unlcok for the Myo is set to permanent, until the doubletap is posed.
    function onUnlock()
        myo.unlock("hold")
        myo.controlMouse(true)
    end

	--The Main loop of the program, it takes the pose then gives it an edge.
    function onPoseEdge(pose, edge)
        --pose = conditionallySwapWave(pose)
        --myo.debug("onPoseEdge: " .. pose .. ": " .. edge)
        fn = bindings[pose]
        if fn then
            keyEdge = edge == "off" and "up" or "down" or "press"
            fn(keyEdge)
        end
	end
