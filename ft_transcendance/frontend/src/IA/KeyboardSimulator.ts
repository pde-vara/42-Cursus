import type { AIAction } from './types.js';
import { keys } from '../models/gamModels.js';


export class KeyboardSimulator {
    private currentKey: string | null = null;
    private keyUpKey: string;
    private keyDownKey: string;

    constructor(upKey: string = 'ArrowUp', downKey: string = 'ArrowDown') {
        this.keyUpKey = upKey;
        this.keyDownKey = downKey;
    }

    public pressContinuous(action: AIAction): void {
        switch (action) {
            case 'UP':
                this.setKeyState(this.keyUpKey, true);
                this.setKeyState(this.keyDownKey, false);
                this.currentKey = this.keyUpKey;
                break;
            case 'DOWN':
                this.setKeyState(this.keyDownKey, true);
                this.setKeyState(this.keyUpKey, false);
                this.currentKey = this.keyDownKey;
                break;
            case 'IDLE':
                this.setKeyState(this.keyUpKey, false);
                this.setKeyState(this.keyDownKey, false);
                this.currentKey = null;
                break;
        }
    }

    private releaseKey(key: string): void {
        keys[key] = false;

        if (this.currentKey === key) {
            this.currentKey = null;
        }
    }

    private setKeyState(key: string, state: boolean): void {
        keys[key] = state;
    }

    public releaseAll(): void {
        if (this.currentKey) {
            this.releaseKey(this.currentKey);
        }
    }

    public setKeys(upKey: string, downKey: string): void {
        this.releaseAll();
        this.keyUpKey = upKey;
        this.keyDownKey = downKey;
    }
}